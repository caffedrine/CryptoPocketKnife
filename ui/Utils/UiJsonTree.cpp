#include <QDebug>

#include "UiJsonTree.h"
#include "ui_UiJsonTree.h"


UiJsonTree::UiJsonTree(QWidget *parent, QString RawJson): QWidget(parent), ui(new Ui::UiJsonTree)
{
    ui->setupUi(this);
    this->model = new QJsonModel;
    this->ui->treeView->setModel( this->model );
    this->ui->plainTextEdit->setPlainText(RawJson);
}

UiJsonTree::~UiJsonTree()
{
    delete ui;
    delete this->model;
}

void UiJsonTree::on_plainTextEdit_textChanged()
{
    if( this->ui->plainTextEdit->toPlainText().isEmpty() )
    {
        this->model->clear();
        this->ui->plainTextEdit->setStyleSheet("");
        return;
    }

    QString styleSheetString = "border: 2px solid green;";
    if(!this->model->loadJson( this->ui->plainTextEdit->toPlainText().toUtf8() ) )
    {
        this->model->clear();
        styleSheetString = "border: 2px solid red;";
        //qDebug().nospace().noquote() << "Cannot load JSON";
    }
    this->ui->plainTextEdit->setStyleSheet(styleSheetString);
}
