#include "utils.h"
#include "sha512.h"

QString Utils_Uint8ToHexQStr(uint8_t in)
{
    return QString("%1").arg(in, 2, 16, QLatin1Char( '0' )).toUpper();
}

QString Utils_Uint8ArrToHexQStr(uint8_t *arr, ssize_t len)
{
    QString result = "";
    for( int i = 0; i < len; i++ )
    {
        result += Utils_Uint8ToHexQStr(arr[i]);
        if( i < len - 1 )
            result += " ";
    }
    return result;
}

bool Utils_RawHexStrToArr(QString in_hexstr, uint8_t *out_arr, ssize_t *out_len, ssize_t max_len)
{
    QByteArray input_bytes = QByteArray::fromHex(in_hexstr.toLatin1());

    for( int i = 0; i < max_len; i++ )
    {
        if( i >= input_bytes.length() )
            break;

        out_arr[i] = input_bytes[i];
    }

    if( input_bytes.length() > max_len )
    {
        *out_len = max_len;
        return false;
    }

    *out_len = input_bytes.length();
    return true;
}

bool Utils_Sha512(uint8_t *in_data, ssize_t in_len, uint8_t outData[SHA512_HASH_LENGTH])
{
    struct sha512 hash;

    /* hash secret-key */
    sha512_init(&hash);
    sha512_add(&hash, in_data, (size_t)in_len);
    sha512_final(&hash, outData);

    return true;
}

QString Utils_BytesToPrintableAsciiString(const QByteArray *in_arr)
{
    QString result = "";
    for( int i = 0; i < in_arr->length(); i++ )
    {
        QChar c = QChar(in_arr->at(i));
        if( (c>= 0x20 && c <= 0x7f) || ( c == 0x0A ) )
            result += c;
        else
            result += ".";
    }
    return result;
}

QString Utils_BytesToAlphanumericString(const QByteArray *in_arr)
{
    QString result = "";
    for( int i = 0; i < in_arr->length(); i++ )
    {
        QChar c = QChar(in_arr->at(i));
        if( c.isDigit() || (c >= 0x41 && c <= 0x5A ) || (c >= 0x61 && c <= 0x7A ))
            result += c;
        else
            result += ".";
    }
    return result;
}

QString Utils_BytesToBinaryString(const QByteArray *in_arr)
{
    QString result = "";
    for( int i = 0; i < in_arr->length(); i++ )
    {
        result += QString("%1").arg((uint8_t)in_arr->at(i), 8, 2, QChar('0')) + " ";
    }
    return result.trimmed();
}

QString Utils_BytesToDECString(const QByteArray *in_arr)
{
    QString result = "";
    for( int i = 0; i < in_arr->length(); i++ )
    {
        result += QString::number((uint8_t)in_arr->at(i)) + " ";
    }
    return result.trimmed();
}

QString ParseCertOrCsrFromFileToHexStr(QString fileName)
{
    // Open file and create reading stream
    QFile f(fileName);
    if (!f.open(QFile::ReadOnly))
            return "";

    // Read file bytes
    QByteArray fileContent = f.readAll();

     // Read content into UI
    QString delimitator = "-----";
    if( QString(fileContent).contains(delimitator) )
    {
        // Convert certificate from B64 to binary format.
        QString input = QString(fileContent).replace(",", "").replace(" ", "").replace("\n", "");
        input = input.split(delimitator)[2].split(delimitator)[0];
        return QByteArray::fromBase64(input.toUtf8()).toHex(' ');
    }
    else
    {
        // Content already in as binary. Just send it to ui
        return fileContent.toHex(' ');
    }
}
