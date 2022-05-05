#include "Hash.h"

#include "sha1.h"
#include "sha2.h"
#include "md5.h"

namespace Crypto::Hash
{
    QByteArray MD5(QByteArray input)
    {
        BYTE buf[16];
        MD5_CTX ctx;

        md5_init(&ctx);
        md5_update(&ctx, (BYTE *) input.constData(), (ssize_t) input.length());
        md5_final(&ctx, buf);

        return QByteArray((char *) buf, sizeof(buf));
    }

    QByteArray SHA1(QByteArray input)
    {
        BYTE buf[SHA1_BLOCK_SIZE];
        SHA1_CTX ctx;

        sha1_init(&ctx);
        sha1_update(&ctx, (BYTE *) input.constData(), (ssize_t) input.length());
        sha1_final(&ctx, buf);

        return QByteArray((char *) buf, sizeof(buf));
    }

    QByteArray SHA2_224(QByteArray input)
    {
        unsigned char digest[SHA224::DIGEST_SIZE];
        memset(digest,0,SHA224::DIGEST_SIZE);

        SHA224 ctx = SHA224();
        ctx.init();
        ctx.update((unsigned char *)input.constData(), input.size());
        ctx.final(digest);

        return QByteArray((char *)digest, SHA224::DIGEST_SIZE);
    }

    QByteArray SHA2_256(QByteArray input)
    {
        unsigned char digest[SHA256::DIGEST_SIZE];
        memset(digest,0,SHA256::DIGEST_SIZE);

        SHA256 ctx = SHA256();
        ctx.init();
        ctx.update((unsigned char *)input.constData(), input.size());
        ctx.final(digest);

        return QByteArray((char *)digest, SHA256::DIGEST_SIZE);
    }

    QByteArray SHA2_384(QByteArray input)
    {
        unsigned char digest[SHA384::DIGEST_SIZE];
        memset(digest,0,SHA384::DIGEST_SIZE);

        SHA384 ctx = SHA384();
        ctx.init();
        ctx.update((unsigned char *)input.constData(), input.size());
        ctx.final(digest);
        return QByteArray((char *)digest, SHA384::DIGEST_SIZE);
    }

    QByteArray SHA2_512(QByteArray input)
    {
        unsigned char digest[SHA512::DIGEST_SIZE];
        memset(digest,0,SHA512::DIGEST_SIZE);

        SHA512 ctx = SHA512();
        ctx.init();
        ctx.update((unsigned char *)input.constData(), input.size());
        ctx.final(digest);

        return QByteArray((char *)digest, SHA512::DIGEST_SIZE);
    }

    QByteArray SHA2_512_224(QByteArray input)
    {
//        unsigned char digest[SHA512_224::DIGEST_SIZE];
//        memset(digest,0,SHA512_224::DIGEST_SIZE);
//
//        SHA512_224 ctx = SHA512_224();
//        ctx.init();
//        ctx.update((unsigned char *)input.constData(), input.size());
//        ctx.final(digest);
//
//        return QByteArray((char *)digest, SHA512_224::DIGEST_SIZE);
        return QByteArray();
    }

    QByteArray SHA2_512_256(QByteArray input)
    {
        return QByteArray();
    }
}
