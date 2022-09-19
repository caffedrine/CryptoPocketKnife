#include "UiXmlTree.h"
#include "ui_UiXmlTree.h"

UiXmlTree::UiXmlTree(QWidget *parent, QString dom_data): QWidget(parent), ui(new Ui::UiXmlTree)
{
    ui->setupUi(this);
    this->model = new DomModel(QDomDocument());
    this->ui->treeView->setModel( this->model );
    this->ui->plainTextEdit->setPlainText(dom_data);
}

UiXmlTree::~UiXmlTree()
{
    delete ui;
    delete this->model;
}

void UiXmlTree::on_plainTextEdit_textChanged()
{
    if( this->ui->plainTextEdit->toPlainText().isEmpty() )
    {
        if( this->model != nullptr )
        {
            delete this->model;
            this->model = nullptr;
        }
        this->ui->plainTextEdit->setStyleSheet("");
        return;
    }

    QString styleSheetString = "border: 2px solid green;";
    QDomDocument doc;
    if(!doc.setContent(this->ui->plainTextEdit->toPlainText().toUtf8() ) )
    {
        if( this->model != nullptr )
        {
            delete this->model;
            this->model = nullptr;
        }
        styleSheetString = "border: 2px solid red;";
    }
    else
    {
        this->model = new DomModel(doc);
        this->ui->treeView->setModel(this->model);
    }
    this->ui->plainTextEdit->setStyleSheet(styleSheetString);
}
