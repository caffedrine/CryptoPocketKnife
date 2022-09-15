#include "UiHttpWebRequests.h"
#include "ui_UiHttpWebRequests.h"

#include "utils.h"

UiHttpWebRequests::UiHttpWebRequests(QWidget *parent): QWidget(parent), ui(new Ui::UiHttpWebRequests)
{
    ui->setupUi(this);
}

UiHttpWebRequests::~UiHttpWebRequests()
{
    delete ui;
}

void UiHttpWebRequests::on_pushButton_Composer_Submit_clicked()
{
    Utils_PushButtonStartLoading(this->ui->pushButton_Composer_Submit);

    HttpWebRequest request;
    request.setIgnoreSslErrors(true);
    request.CUSTOM(this->ui->lineEdit_Composer_HttpMethod->text().toUtf8(), this->ui->lineEdit_Composer_TargetHost->text(), this->ui->plainTextEdit_ComposerRawHeaders->toPlainText().toUtf8());




    Utils_PushButtonEndLoading(this->ui->pushButton_Composer_Submit);
}
