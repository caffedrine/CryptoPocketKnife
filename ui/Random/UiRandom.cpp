#include "UiRandom.h"
#include "ui_UiRandom.h"

#include "base/utils/utils.h"

UiRandom::UiRandom(QWidget *parent): QWidget(parent), ui(new Ui::UiRandom)
{
    ui->setupUi(this);

    entropyAnalyzer = new UiEntropyAnalyzer(this);
    entropyAnalyzer->setWindowFlags(Qt::Widget);
    this->ui->gridLayout_EntropyAnalyzer->addWidget(entropyAnalyzer);
}

UiRandom::~UiRandom()
{
    delete ui;
}
