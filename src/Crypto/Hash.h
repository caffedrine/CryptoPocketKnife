#ifndef HASH_H
#define HASH_H

#include <QByteArray>

namespace Crypto::Hash
{
    QByteArray MD5(QByteArray input);
    QByteArray SHA1(QByteArray input);
    QByteArray SHA2_224(QByteArray input);
    QByteArray SHA2_256(QByteArray input);
    QByteArray SHA2_384(QByteArray input);
    QByteArray SHA2_512(QByteArray input);
    QByteArray SHA2_512_224(QByteArray input);
    QByteArray SHA2_512_256(QByteArray input);
}


#endif // HASH_H
