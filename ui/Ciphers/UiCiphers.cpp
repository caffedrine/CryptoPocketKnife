#include "UiCiphers.h"
#include "ui_UiCiphers.h"

#include "utils.h"
#include <aes.h>

UiCiphers::UiCiphers(QWidget *parent): QWidget(parent), ui(new Ui::UiCiphers)
{
    ui->setupUi(this);
}

UiCiphers::~UiCiphers()
{
    delete ui;
}

/*    _____ _       _
     / ____(_)     | |
    | |     _ _ __ | |__   ___ _ __ ___
    | |    | | '_ \| '_ \ / _ \ '__/ __|
    | |____| | |_) | | | |  __/ |  \__ \
     \_____|_| .__/|_| |_|\___|_|  |___/
             | |
             |_|
*/
void UiCiphers::on_ciphers_AES_pushButton_Encrypt_clicked()
{
    ssize_t aerKeyIn_len, aesIvIn_len, aesInput_len, aesOutput_len = 0;
    uint8_t aerKeyIn[1024], aesIvIn[1024];
    uint8_t aesInput[8192], aesOutput[8192];

    // Read data from ui
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesKey->text(), aerKeyIn, &aerKeyIn_len, sizeof(aerKeyIn));
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesIV->text(), aesIvIn, &aesIvIn_len, sizeof(aesIvIn));
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesInput->toPlainText(), aesInput, &aesInput_len, sizeof(aesInput));

    // Encrypt given input
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, aerKeyIn, aesIvIn);
    AES_CBC_encrypt_buffer(&ctx, aesInput, aesInput_len);
    // Copy to output
    memcpy(aesOutput, aesInput, aesInput_len);
    aesOutput_len = aesInput_len;

    // Write output to ui
    ui->ciphers_AES_textEdit_AesOutput->setText(Utils_Uint8ArrToHexQStr(aesOutput, aesOutput_len));
}

void UiCiphers::on_ciphers_AES_pushButton_Decrypt_clicked()
{
    ssize_t aerKeyIn_len, aesIvIn_len, aesInput_len, aesOutput_len;
    uint8_t aerKeyIn[1024], aesIvIn[1024];
    uint8_t aesInput[8192], aesOutput[8192];

    // Read data from ui
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesKey->text(), aerKeyIn, &aerKeyIn_len, sizeof(aerKeyIn));
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesIV->text(), aesIvIn, &aesIvIn_len, sizeof(aesIvIn));
    Utils_RawHexStrToArr(ui->ciphers_AES_textEdit_AesInput->toPlainText(), aesInput, &aesInput_len, sizeof(aesInput));

    // Decrypt given input
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, aerKeyIn, aesIvIn);
    AES_CBC_decrypt_buffer(&ctx, aesInput, aesInput_len);
    // Copy to output
    memcpy(aesOutput, aesInput, aesInput_len);
    aesOutput_len = aesInput_len;

    // Write output to ui
    ui->ciphers_AES_textEdit_AesOutput->setText(Utils_Uint8ArrToHexQStr(aesOutput, aesOutput_len));
}
