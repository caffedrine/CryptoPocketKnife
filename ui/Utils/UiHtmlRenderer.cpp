#include "UiHtmlRenderer.h"
#include "ui_UiHtmlRenderer.h"


UiHtmlRenderer::UiHtmlRenderer(QWidget *parent, QString html_content): QWidget(parent), ui(new Ui::UiHtmlRenderer)
{
    ui->setupUi(this);
    this->model = new QDomModel(QDomDocument());
    this->ui->treeView->setModel( this->model );
    this->ui->plainTextEdit->setPlainText(html_content);
}

UiHtmlRenderer::~UiHtmlRenderer()
{
    delete ui;
}

void UiHtmlRenderer::on_plainTextEdit_textChanged()
{
    if( this->ui->plainTextEdit->toPlainText().isEmpty() )
    {
        if( this->model != nullptr )
        {
            delete this->model;
            this->model = nullptr;
        }
        this->ui->plainTextEdit->setStyleSheet("");
        this->ui->textEdit_HtmlOutput->clear();
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
        this->model = new QDomModel(doc);
        this->ui->treeView->setModel(this->model);
    }

    this->ui->textEdit_HtmlOutput->setHtml( this->ui->plainTextEdit->toPlainText() );
    this->ui->treeView->setStyleSheet(styleSheetString);
}
