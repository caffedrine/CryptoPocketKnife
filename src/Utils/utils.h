#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QCryptographicHash>
#include <QFile>
#include <QRegularExpression>
#include <QDebug>
#include <QUrl>
#include <QHostAddress>

QString Utils_Uint8ToHexQStr(uint8_t in);
QString Utils_Uint8ArrToHexQStr(uint8_t *arr, ssize_t len);
QString Utils_QByteArrayToHexQStr(const QByteArray& bytes_arr);
QByteArray Utils_RawHexStrToQByteArr(QString in_hexstr);
bool Utils_RawHexStrToArr(QString in_hexstr, uint8_t *out_arr, ssize_t *out_len, ssize_t max_len);
bool Utils_Sha512(uint8_t *in_data, ssize_t in_len, uint8_t outData[64]);

QString Utils_BytesToPrintableAsciiString(const QByteArray *in_arr);
QString Utils_BytesToAlphanumericString(const QByteArray *in_arr);
QString Utils_BytesToBinaryString(const QByteArray *in_arr);
QString Utils_BytesToDECString(const QByteArray *in_arr);

QString ParseCertOrCsrFromFileToHexStr(QString fileName);

QStringList Utils_ExtractAllUrls(const QString& inputText);
QStringList Utils_ExtractAllHosts(const QString &input);

bool Utils_IsValidIPv4(const QString &input);
bool Utils_IsValidIPv6(const QString &input);

void Utils_NumericListSort(QStringList *list);
bool Utils_FileExists(QString fileName);

template <class T>
static QString join(const QList<T> &list,
                    const QString &separator,
                    const std::function< QString (const typename QList<T>::value_type &) > toStringFunction);

#endif // UTILS_H
