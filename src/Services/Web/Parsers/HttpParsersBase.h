#ifndef _HTTPPARSERSBASE_H_
#define _HTTPPARSERSBASE_H_

#include <QByteArray>
#include <QString>
#include <QList>
#include <QMap>

#include "utils.h"

namespace Services { namespace Parsers {

    class HttpParsersBase
    {
    public:
        void addData(QByteArray chunkData);

        bool HaveHeader(QByteArray headerName);
        QByteArray GetHeaderByName(QByteArray headerName);
        QByteArray GetRaw();
        QByteArray GetRawHeaders();
        QByteArray GetRawBody();
        QByteArray GetHttpVersion() { return this->HttpVersion; };
        QString GetParseFailReason();

        bool IsValidHttpData();
        bool IsCompleteHttpData();

    protected:
        HttpParsersBase() = default;

        enum ParserState
        {
            PARSE_FIRST_LINE,
            PARSE_HEADERS,
            PARSE_BODY,
            PARSE_COMPLETED,
            PARSE_FAILED,
        };

        QByteArray UnprocessedChunk;
        QByteArray RawData;
        ParserState State = PARSE_FIRST_LINE;
        QString ParseFailReason;

        QByteArray HttpVersion;
        QList<QByteArray> HeadersNames;
        QList<QByteArray> HeadersVals;
        QMap<QByteArray, int>HeaderIdx; // Can't use single Map due to duplicate headers
        QByteArray Body;

        virtual QByteArray GetFirstLine() = 0;
        virtual void clear();

        virtual void ParseFirstLine() = 0;
        virtual void ParseHeaders();
        virtual void ParseBody();
    };

}}; // Namespaces

#endif //_HTTPPARSERSBASE_H_
