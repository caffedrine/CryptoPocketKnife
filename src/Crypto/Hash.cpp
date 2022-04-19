#include "Hash.h"

#include "sha1.h"
#include "sha256.h"
#include "md5.h"

namespace Crypto::Hash
{

    QByteArray SHA1(QByteArray input)
    {
        BYTE buf[SHA1_BLOCK_SIZE];
        SHA1_CTX ctx;

        sha1_init(&ctx);
        sha1_update(&ctx, (BYTE *) input.constData(), (ssize_t) input.length());
        sha1_final(&ctx, buf);

        return QByteArray((char *) buf, sizeof(buf));
    }

    QByteArray SHA2_256(QByteArray input)
    {
        BYTE buf[SHA256_BLOCK_SIZE];
        SHA256_CTX ctx;

        sha256_init(&ctx);
        sha256_update(&ctx, (BYTE *) input.constData(), (ssize_t) input.length());
        sha256_final(&ctx, buf);

        return QByteArray((char *) buf, sizeof(buf));
    }

    QByteArray MD5(QByteArray input)
    {
        BYTE buf[16];
        MD5_CTX ctx;

        md5_init(&ctx);
        md5_update(&ctx, (BYTE *) input.constData(), (ssize_t) input.length());
        md5_final(&ctx, buf);

        return QByteArray((char *) buf, sizeof(buf));
    }

}
