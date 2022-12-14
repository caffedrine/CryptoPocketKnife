#include "HttpParsersBase.h"

namespace Services { namespace Parsers {

    void HttpParsersBase::addData(QByteArray chunkData)
    {
        this->UnprocessedChunk.append(chunkData);
        this->RawData.append(chunkData);

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

    bool HttpParsersBase::HaveHeader(QByteArray headerName)
    {
        return this->HeaderIdx.find(headerName) != this->HeaderIdx.end();
    }

    QByteArray HttpParsersBase::GetHeaderByName(QByteArray headerName)
    {
        if( this->HeaderIdx.find(headerName) != this->HeaderIdx.end())
        {
            return this->HeadersVals.at(this->HeaderIdx[headerName]);
        }
        return QByteArray();
    }

    QByteArray HttpParsersBase::GetRaw()
    {
        return this->RawData;
    }

    QByteArray HttpParsersBase::GetRawBody()
    {
        return this->Body;
    }

    QByteArray HttpParsersBase::GetRawHeaders()
    {
        QByteArray output = this->GetFirstLine() + "\r\n";
        int idx = 0;
        for(const QByteArray &headerName: this->HeadersNames)
        {
            output += headerName + ":" + this->HeadersVals.at(idx++) + "\r\n";
        }
        return output;
    }

    QString HttpParsersBase::GetParseFailReason()
    {
        return this->ParseFailReason;
    }

    bool HttpParsersBase::IsValidHttpData()
    {
        return this->State != PARSE_COMPLETED;
    }

    bool HttpParsersBase::IsCompleteHttpData()
    {
        return this->State == PARSE_COMPLETED;
    }

    void HttpParsersBase::clear()
    {
        this->UnprocessedChunk.clear();
        this->RawData.clear();
        this->State = PARSE_FIRST_LINE;
        this->ParseFailReason.clear();

        this->HttpVersion.clear();
        this->HeadersNames.clear();
        this->HeadersVals.clear();
        this->HeaderIdx.clear();
        this->Body.clear();
    }

    void HttpParsersBase::ParseHeaders()
    {
        if(!this->UnprocessedChunk.contains("\r\n"))
            return;

        QByteArray headersToBeProcessed;

        // Full body received?
        if(this->UnprocessedChunk.contains("\r\n\r\n"))
        {
            headersToBeProcessed = this->UnprocessedChunk.left(this->UnprocessedChunk.indexOf("\r\n\r\n"));
            this->UnprocessedChunk.remove(0, this->UnprocessedChunk.indexOf("\r\n\r\n") + 4);
            this->State = PARSE_BODY;
        }
        else
        {
            // Complete headers received?
            if(this->UnprocessedChunk.endsWith("\r\n"))
            {
                headersToBeProcessed = this->UnprocessedChunk;
                this->UnprocessedChunk.clear();
            }
            else if(this->UnprocessedChunk.contains("\r\n")) // Last header from list is not completed? leave it for next time and process what we have so far
            {
                headersToBeProcessed = this->UnprocessedChunk.left(this->UnprocessedChunk.lastIndexOf("\r\n"));
                this->UnprocessedChunk.remove(0, this->UnprocessedChunk.lastIndexOf("\r\n"));
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
            QByteArray headerValue = header.right(header.count() - 1 - header.indexOf(':'));

            this->HeadersVals.append(headerValue);
            this->HeadersNames.append(headerName);
            this->HeaderIdx[headerName] = this->HeadersNames.count() - 1;
        }
    }

    void HttpParsersBase::ParseBody()
    {
        this->Body.append(this->UnprocessedChunk);
        this->UnprocessedChunk.clear();

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

}}; // Parsers
