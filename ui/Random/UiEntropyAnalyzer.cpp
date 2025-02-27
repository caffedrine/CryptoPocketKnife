#include "UiEntropyAnalyzer.h"
#include "ui_UiEntropyAnalyzer.h"

#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>
#include "RandomAnalyzer.h"

UiEntropyAnalyzer::UiEntropyAnalyzer(QWidget *parent): QMainWindow(parent), ui(new Ui::UiEntropyAnalyzer)
{
    ui->setupUi(this);

    // Enable drops for raw data to drop file and display its content
    this->setAcceptDrops(false);

    this->ui->plainTextEdit_Output->setAcceptDrops(true);
    QObject::connect(this->ui->plainTextEdit_Output, SIGNAL( OnDraggedFile(QString) ), this, SLOT(OnRawDataFileDragged(QString)) );
}

UiEntropyAnalyzer::~UiEntropyAnalyzer()
{
    delete ui;
}

void UiEntropyAnalyzer::on_pushButton_AnalyzeInput_clicked()
{
    if( this->ui->lineEdit_InputBytes->text().isEmpty() )
        return;

    RandomAnalyzer a(this->ui->checkBox_BinaryMode->isChecked(), Base::Utils::ByteArrays::RawHexStrToQByteArr(this->ui->lineEdit_InputBytes->text()));

    this->ui->plainTextEdit_Output->setPlainText( a.GetResultHumanReadable() );

}

void UiEntropyAnalyzer::on_pushButton_LoadFiles_clicked()
{

}

void UiEntropyAnalyzer::OnRawDataFileDragged(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        return;

    RandomAnalyzer a(this->ui->checkBox_BinaryMode->isChecked(), file.readAll());

    this->ui->plainTextEdit_Output->setPlainText( a.GetResultHumanReadable() );

    file.close();
}
