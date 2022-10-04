#include "RawHttpResponseParser.h"

#include <QDebug>

namespace Services { namespace Parsers {

    RawHttpResponseParser::RawHttpResponseParser()
    {
        this->State = PARSE_FIRST_LINE;
    }

    RawHttpResponseParser::RawHttpResponseParser(QByteArray responseChunk)
    {
        this->State = PARSE_FIRST_LINE;
        this->addData(responseChunk);
    }

    void RawHttpResponseParser::addData(QByteArray responseChunk)
    {
        this->UnprocessedResponseChunk.append(responseChunk);
        this->RawResponse.append(responseChunk);

        if(this->State == PARSE_FIRST_LINE)
        {
            this->ParseFirstLine();
        }

        if(this->State == PARSE_HEADERS)
        {
            this->ParseHeaders();
        }

        if(this->State == PARSE_BODY || this->State == PARSE_COMPLETED)
        {
            this->ParseBody();
        }
    }

    int RawHttpResponseParser::GetResponseCode()
    {
        return this->ResponseCode;
    }

    QByteArray RawHttpResponseParser::GetResponseCodeDescription()
    {
        if(!this->UnprocessedResponseChunk.isEmpty())
            return QByteArray();

        return this->ResponseCodeDesc;
    }

    bool RawHttpResponseParser::IsKeepAliveEnabled()
    {
        return false;
    }

    bool RawHttpResponseParser::IsValidResponse()
    {
        return this->State != PARSE_COMPLETED;
    }

    bool RawHttpResponseParser::IsCompleteResponse()
    {
        return this->State == PARSE_COMPLETED;
    }

    QByteArray RawHttpResponseParser::GetHeaderByName(QByteArray headerName)
    {
        if( this->HeaderIdx.find(headerName) != this->HeaderIdx.end())
        {
            return this->HeadersVals.at(this->HeaderIdx[headerName]);
        }
        return QByteArray();
    }

    QByteArray RawHttpResponseParser::GetRawResponse()
    {
        QByteArray output = this->HttpVersion + " " + (this->ResponseCode > 0 ? QString::number(this->ResponseCode).toUtf8() : " ") + " " + this->ResponseCodeDesc + "\r\n";
        int i = 0;
        for(const QByteArray &headerName: this->HeadersNames)
        {
            output += headerName + ":" + this->HeadersVals.at(i++) + "\r\n";
        }

        output += "\r\n";
        output += this->Body;

        if(output != this->RawResponse)
        {
            qWarning().nospace().noquote() << "Output rendered is different than the output received (parsing error: " << this->ParseFailReason << ")";
            qWarning().nospace().noquote() << "Recv: " << this->RawResponse;
            qWarning().nospace().noquote() << "Built: " << output;
        }

        return output;
    }

    QByteArray RawHttpResponseParser::GetRawBody()
    {
        return this->Body;
    }

    QByteArray RawHttpResponseParser::GetRawHeaders()
    {
        QByteArray output = this->HttpVersion + " " + (this->ResponseCode > 0 ? QString::number(this->ResponseCode).toUtf8() : " ") + " " + this->ResponseCodeDesc + "\r\n";
        int idx = 0;
        for(const QByteArray &headerName: this->HeadersNames)
        {
            output += headerName + ":" + this->HeadersVals.at(idx++) + "\r\n";
        }
        return output;
    }

    QString RawHttpResponseParser::GetParseFailReason()
    {
        return this->ParseFailReason;
    }

    void RawHttpResponseParser::ParseFirstLine()
    {
        if(!this->UnprocessedResponseChunk.contains("\r\n"))
        {
            this->ParseFailReason = "no first line with version detected";
            return;
        }

        // Extract first line and remove it from buffer
        QByteArray firstLine = this->UnprocessedResponseChunk.left(this->UnprocessedResponseChunk.indexOf("\r\n"));
        this->UnprocessedResponseChunk.remove(0, this->UnprocessedResponseChunk.indexOf("\r\n") + 2);

        // Three elements separated by three spaces
        if(!firstLine.contains(' '))
        {
            this->ParseFailReason = "first line does not contain properly formatted version and response code (no spaces found)";
            this->State = PARSE_FAILED;
            return;
        }

        // First line must contain 3 elements
        QByteArrayList elements = firstLine.split(' ');
        if(elements.count() < 2)
        {
            this->ParseFailReason = "first line does not contain properly formatted version and response code (there must be 2-3 elements found)";
            this->State = PARSE_FAILED;
            return;
        }

        // First element must be HTTP version
        if(!elements[0].toLower().startsWith("http/"))
        {
            this->ParseFailReason = "invalid http version";
            this->State = PARSE_FAILED;
            return;
        }
        this->HttpVersion = elements[0];

        bool isNumber = false;
        int intNo = QString(elements[1]).toInt(&isNumber);
        if(!isNumber)
        {
            this->ParseFailReason = "invalid response code";
            this->State = PARSE_FAILED;
            return;
        }
        this->ResponseCode = intNo;
        if( elements.count() > 2 )
        {
            for( int i = 2; i < elements.count(); i++ )
            {
                this->ResponseCodeDesc += elements[i];
                if( i !=elements.count()-1 )
                    this->ResponseCodeDesc += " ";
            }
        }
        else
        {
            this->ResponseCodeDesc = "";
        }

        // If all is good so far, advance to next state and parse headers
        this->State = PARSE_HEADERS;
    }

    void RawHttpResponseParser::ParseHeaders()
    {
        if(!this->UnprocessedResponseChunk.contains("\r\n"))
            return;

        QByteArray headersToBeProcessed;

        // Full body received?
        if(this->UnprocessedResponseChunk.contains("\r\n\r\n"))
        {
            headersToBeProcessed = this->UnprocessedResponseChunk.left(this->UnprocessedResponseChunk.indexOf("\r\n\r\n"));
            this->UnprocessedResponseChunk.remove(0, this->UnprocessedResponseChunk.indexOf("\r\n\r\n") + 4);
            this->State = PARSE_BODY;
        }
        else
        {
            // Complete headers received?
            if(this->UnprocessedResponseChunk.endsWith("\r\n"))
            {
                headersToBeProcessed = this->UnprocessedResponseChunk;
                this->UnprocessedResponseChunk.clear();
            }
            else if(this->UnprocessedResponseChunk.contains("\r\n")) // Last header from list is not completed? leave it for next time and process what we have so far
            {
                headersToBeProcessed = this->UnprocessedResponseChunk.left(this->UnprocessedResponseChunk.lastIndexOf("\r\n"));
                this->UnprocessedResponseChunk.remove(0, this->UnprocessedResponseChunk.lastIndexOf("\r\n"));
            }
        }

        // Read headers
        for(QByteArray header: SplitByteArray(headersToBeProcessed, "\r\n"))
        {
            if(!header.contains(":"))
            {
                this->State = PARSE_FAILED;
                this->ParseFailReason = "invalid header detected: '" + header + "'";
                return;
            }

            QByteArray headerName = header.left(header.indexOf(':'));
            QByteArray headerValue = header.last(header.count() - 1 - header.indexOf(':'));

            this->HeadersVals.append(headerValue);
            this->HeadersNames.append(headerName);
            this->HeaderIdx[headerName] = this->HeadersNames.count() - 1;
        }
    }

    void RawHttpResponseParser::ParseBody()
    {
        this->Body.append(this->UnprocessedResponseChunk);
        this->UnprocessedResponseChunk.clear();

        int expectedLength = -1;
        if(this->HaveHeader("Content-Length"))
        {
            expectedLength = QString(this->GetHeaderByName("Content-Length")).toInt();
        }

        if(expectedLength > -1)
        {
            if(this->Body.count() < expectedLength)
            {
                this->ParseFailReason = "incomplete body, expected " + QString::number(expectedLength) + ", received " + QString::number(this->Body.count());
            }
            else
            {
                this->State = PARSE_COMPLETED;
                // Also clear last error when successfully finished
                this->ParseFailReason = "";
            }
        }
        else
        {
            this->State = PARSE_COMPLETED;
            // Also clear last error when successfully finished
            this->ParseFailReason = "";
        }
    }

    bool RawHttpResponseParser::HaveHeader(QByteArray headerName)
    {
        return this->HeaderIdx.find(headerName) != this->HeaderIdx.end();
    }

    void RawHttpResponseParser::clear()
    {
        this->UnprocessedResponseChunk.clear();
        this->RawResponse.clear();
        this->State = PARSE_FIRST_LINE;
        this->ParseFailReason.clear();

        this->HttpVersion.clear();
        this->ResponseCode = -1;
        this->ResponseCodeDesc.clear();
        this->HeadersNames.clear();
        this->HeadersVals.clear();
        this->HeaderIdx.clear();
        this->Body.clear();
    }
}} // Namespaces
