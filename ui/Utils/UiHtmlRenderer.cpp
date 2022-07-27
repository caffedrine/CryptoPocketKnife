#include "UiHtmlRenderer.h"
#include "ui_UiHtmlRenderer.h"


UiHtmlRenderer::UiHtmlRenderer(QWidget *parent) :
        QWidget(parent), ui(new Ui::UiHtmlRenderer)
{
    ui->setupUi(this);
}

UiHtmlRenderer::~UiHtmlRenderer()
{
    delete ui;
}
