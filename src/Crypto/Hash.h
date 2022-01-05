#ifndef HASH_H
#define HASH_H

#include <QByteArray>

namespace Crypto
{
    namespace Hash
    {
        QByteArray SHA1(QByteArray input);
        QByteArray SHA2_256(QByteArray input);
        QByteArray MD5(QByteArray input);
    }
}


#endif // HASH_H
