#include "MathExpEvalWidget.h"
#include "ui_MathExpEvalWidget.h"

#include "tinyexpr.h"

MathExpEvalWidget::MathExpEvalWidget(QWidget *parent): QWidget(parent), ui(new Ui::MathExpEvalWidget)
{
    ui->setupUi(this);

    this->ui->plainTextEdit_CompilationOutput->resize(this->ui->plainTextEdit_MathExpInput->width(), this->ui->plainTextEdit_MathExpInput->height()/3);
}

MathExpEvalWidget::~MathExpEvalWidget()
{
    delete ui;
}
