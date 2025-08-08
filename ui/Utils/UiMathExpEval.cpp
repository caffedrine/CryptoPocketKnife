#include <QMainWindow>
#include "UiMathExpEval.h"
#include "ui_UiMathExpEval.h"

#include <QWidgetMathEvaluator/UiMathEvaluator.h>

UiMathExpEval::UiMathExpEval(QWidget *parent): QWidget(parent), ui(new Ui::UiMathExpEval)
{
    ui->setupUi(this);

    // Init math exp evaluator
    UiMathEvaluatorSettings sett;
    sett.EnableEditing = true;
    sett.ShowToolbox = true;

    UiMathEvaluator *math = new UiMathEvaluator();
    math->UpdateUiSettings(sett);
    this->ui->verticalLayout_Widget->addWidget(math);
}

UiMathExpEval::~UiMathExpEval()
{
    delete ui;
}

void UiMathExpEval::on_pushButton_NewWindow_clicked()
{
    QMainWindow *newWindow = new QMainWindow(this);
    newWindow->setWindowTitle("Math Expression Evaluator");

    // Init math exp evaluator
    UiMathEvaluatorSettings sett;
    sett.EnableEditing = true;
    sett.ShowToolbox = true;

    UiMathEvaluator *math = new UiMathEvaluator();
    math->UpdateUiSettings(sett);

    // Set new window attributes
    newWindow->resize(math->size());
    newWindow->setAttribute(Qt::WA_DeleteOnClose);

    // Set MathExpEvalWidget as the central widget of the new window
    newWindow->setCentralWidget(math);

    // Show the new window
    newWindow->show();
}