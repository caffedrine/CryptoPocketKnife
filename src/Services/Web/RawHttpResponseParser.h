#ifndef _RAWHTTPRESPONSEPARSER_H_
#define _RAWHTTPRESPONSEPARSER_H_

#include <QByteArray>
#include <QMap>
#include "utils.h"

namespace Services { namespace Parsers {

    class RawHttpResponseParser
    {
    public:
        RawHttpResponseParser();
        RawHttpResponseParser(QByteArray responseChunk);
        void addData(QByteArray responseChunk);

        int GetResponseCode();
        QByteArray GetResponseCodeDescription();
        bool IsKeepAliveEnabled();
        bool IsValidResponse();
        bool IsCompleteResponse();
        bool HaveHeader(QByteArray headerName);
        QByteArray GetHeaderByName(QByteArray headerName);
        QByteArray GetRawResponse();
        QByteArray GetRawHeaders();
        QByteArray GetRawBody();
        QString GetParseFailReason();
        QByteArray GetHttpVersion() { return this->HttpVersion; };
        int GetHttpResponseCode() { return this->ResponseCode; };
        QByteArray GetHttpResponseCodeDescription() { return this->ResponseCodeDesc; };

        void clear();

    private:
        enum ParserState
        {
            PARSE_FIRST_LINE,
            PARSE_HEADERS,
            PARSE_BODY,
            PARSE_COMPLETED,
            PARSE_FAILED,
        };

        QByteArray UnprocessedResponseChunk;
        QByteArray RawResponse;
        ParserState State = PARSE_FIRST_LINE;
        QString ParseFailReason;

        QByteArray HttpVersion;
        int ResponseCode = -1;
        QByteArray ResponseCodeDesc;
        QList<QByteArray> HeadersNames;
        QList<QByteArray> HeadersVals;
        QMap<QByteArray, int>HeaderIdx; // Can't use single Map due to duplicate headers
        QByteArray Body;

        void ParseFirstLine();
        void ParseHeaders();
        void ParseBody();
    };

}} // Namespaces

#endif //_RAWHTTPRESPONSEPARSER_H_
