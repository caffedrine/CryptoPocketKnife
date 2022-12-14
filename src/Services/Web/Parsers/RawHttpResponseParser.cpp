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

    bool RawHttpResponseParser::IsKeepAliveEnabled()
    {
        return false;
    }

    void RawHttpResponseParser::ParseFirstLine()
    {
        if(!this->UnprocessedChunk.contains("\r\n"))
        {
            this->ParseFailReason = "no first line with version detected";
            return;
        }

        // Extract first line and remove it from buffer
        QByteArray firstLine = this->UnprocessedChunk.left(this->UnprocessedChunk.indexOf("\r\n"));
        this->UnprocessedChunk.remove(0, this->UnprocessedChunk.indexOf("\r\n") + 2);

        // Three elements separated by three spaces
        if(!firstLine.contains(' '))
        {
            this->ParseFailReason = "first line does not contain properly formatted version and response code (no spaces found)";
            this->State = PARSE_FAILED;
            return;
        }

        // First line must contain 3 elements
        QByteArrayList elements = firstLine.split(' ');
        if(elements.length() < 2)
        {
            this->ParseFailReason = "first line does not contain properly formatted version and response code (there must be 2-3 elements found)";
            this->State = PARSE_FAILED;
            return;
        }

        // First element must be HTTP version
        if(!elements.first().toLower().startsWith("http/"))
        {
            this->ParseFailReason = "invalid http version";
            this->State = PARSE_FAILED;
            return;
        }
        this->HttpVersion = elements.first();
        elements.pop_front();

        bool isNumber = false;
        int intNo = QString(elements.front()).toInt(&isNumber);
        if(!isNumber)
        {
            this->ParseFailReason = "invalid response code";
            this->State = PARSE_FAILED;
            return;
        }
        this->ResponseCode = intNo;
        elements.pop_front();

        // Whatever is remaining, is the code description
        if( !elements.empty() )
            this->ResponseCodeDesc = elements.join(' ');

        // If all is good so far, advance to next state and parse headers
        this->State = PARSE_HEADERS;
        this->ParseFailReason.clear();
    }

    void RawHttpResponseParser::clear()
    {
        this->ResponseCode = -1;
        this->ResponseCodeDesc.clear();
        HttpParsersBase::clear();
    }

    QByteArray RawHttpResponseParser::GetFirstLine()
    {
        return this->HttpVersion + " " + (this->ResponseCode > 0 ? QString::number(this->ResponseCode).toUtf8() : " ") + " " + this->ResponseCodeDesc;
    }
}} // Namespaces
