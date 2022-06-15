#include "UiShodan.h"
#include "ui_UiShodan.h"

#include <QMessageBox>
#include "Shodan.h"
#include "utils.h"

UiShodan::UiShodan(QWidget *parent): QWidget(parent), ui(new Ui::UiShodan)
{
    ui->setupUi(this);
    QObject::connect(this->ui->pushButton_shodanSettings_SaveKey, SIGNAL(clicked()), this, SLOT(pushButton_shodanSettings_SaveKey_clicked()));
    QObject::connect(this->ui->pushButton_shodanSettings_TestApiKey, SIGNAL(clicked()), this, SLOT(pushButton_shodanSettings_TestApiKey_clicked()));
    QObject::connect(this->ui->pushButton_shodanSettings_GetSearchFilters, SIGNAL(clicked()), this, SLOT(pushButton_shodanSettings_GetSearchFilters_clicked()));

    QObject::connect(this->ui->pushButton_ManualQuery_GetResults, SIGNAL(clicked()), this, SLOT(pushButton_ManualQuery_GetResults_clicked()));
    QObject::connect(this->ui->pushButton_ManualQuery_Count, SIGNAL(clicked()), this, SLOT(pushButton_ManualQuery_Count_clicked()));


    this->ui->lineEdit_shodanSettings_ApiKey->setText( UserSettings->Get_OSINT_ShodanApiKey() );
}

UiShodan::~UiShodan()
{
    delete ui;
}

void UiShodan::pushButton_shodanSettings_SaveKey_clicked()
{
    UserSettings->Set_OSINT_ShodanApiKey( this->ui->lineEdit_shodanSettings_ApiKey->text() );
}

void UiShodan::pushButton_shodanSettings_TestApiKey_clicked()
{
    Utils_PushButtonStartLoading( this->ui->pushButton_shodanSettings_TestApiKey );

    Shodan shodan( UserSettings->Get_OSINT_ShodanApiKey() );
    Utils_MsgBox("Shodan reply", shodan.GetAccountInfo());

    Utils_PushButtonEndLoading( this->ui->pushButton_shodanSettings_TestApiKey );

}

void UiShodan::pushButton_shodanSettings_GetSearchFilters_clicked()
{
    Utils_PushButtonStartLoading( this->ui->pushButton_shodanSettings_GetSearchFilters );

    Shodan shodan( UserSettings->Get_OSINT_ShodanApiKey() );
    Utils_RichTextBoxPopup("Shodan reply", shodan.GetSearchFilters());

    Utils_PushButtonEndLoading( this->ui->pushButton_shodanSettings_GetSearchFilters );
}

void UiShodan::pushButton_ManualQuery_GetResults_clicked()
{
    const int RetryAttempts = 5;
    QString pushButtonOrigText = this->ui->pushButton_ManualQuery_GetResults->text();

    //QMap<QString, QMap<QString, QString>>
    this->ui->plainTextEdit_ManualQuery_Results->clear();
    this->ui->lineEdit_ManualQuery_Count->clear();

    Utils_PushButtonStartLoading( this->ui->pushButton_ManualQuery_GetResults );

    QString header = "ip,timestamp,product,country,isp,hostname,asn";
    this->ui->plainTextEdit_ManualQuery_Results->setPlainText(header);

    Shodan shodan( UserSettings->Get_OSINT_ShodanApiKey() );
    int resultsCount = shodan.GetCountByQuery(this->ui->lineEdit_ManualQuery_Query->text()).toInt();
    this->ui->lineEdit_ManualQuery_Count->setText(QString::number(resultsCount));

    int CurrentAttempts = 0;
    for( int i = 1; i <= resultsCount/100 + 1; i++ )
    {
        if( CurrentAttempts > RetryAttempts )
        {
            qDebug().noquote().nospace() << "Maximum attempts reached for page " << i << ". Breaking the execution";
            break;
        }

        this->ui->pushButton_ManualQuery_GetResults->setText(pushButtonOrigText + " " + QString::number(i) + "/" + QString::number((resultsCount/100) + 1));
        quint64 startTimestamp = QDateTime::currentMSecsSinceEpoch();
        QMap<QString, QJsonDocument> results = shodan.GetResultsByByQuery(this->ui->lineEdit_ManualQuery_Query->text(), i);
        if(results.contains("error"))
        {
            Utils_Alert("Shodan error detected", results["error"].object().value("error").toString());
            i -= 1;
            CurrentAttempts++;
            continue;
        }

        for(auto r: results.toStdMap())
        {
            QString line = r.second.object().value("ip_str").toString();
            line += "," + r.second.object().value("timestamp").toString();
            line += "," + r.second.object().value("product").toString();
            line += "," + r.second.object().value("location").toObject().value("country_code").toString();
            line += "," + r.second.object().value("isp").toString();
            line += "," + r.second.object().value("hostnames").toArray()[0].toString();
            line += "," + r.second.object().value("asn").toString();

            this->ui->plainTextEdit_ManualQuery_Results->appendPlainText(line);
        }

        CurrentAttempts = 0;

        while( QDateTime::currentMSecsSinceEpoch() - startTimestamp <= 2000 )
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            SleepMs(10);
        }
    }

    Utils_PushButtonEndLoading( this->ui->pushButton_ManualQuery_GetResults );
    this->ui->pushButton_ManualQuery_GetResults->setText(pushButtonOrigText);
}

void UiShodan::pushButton_ManualQuery_Count_clicked()
{
    Utils_PushButtonStartLoading( this->ui->pushButton_ManualQuery_Count );

    Shodan shodan( UserSettings->Get_OSINT_ShodanApiKey() );
    QString total = shodan.GetCountByQuery(this->ui->lineEdit_ManualQuery_Query->text());
    this->ui->lineEdit_ManualQuery_Count->setText(total);

    Utils_PushButtonEndLoading( this->ui->pushButton_ManualQuery_Count );
}
