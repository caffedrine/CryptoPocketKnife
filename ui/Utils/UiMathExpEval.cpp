#include <QMainWindow>
#include "UiMathExpEval.h"
#include "ui_UiMathExpEval.h"

#include "MathExpEvalWidget.h"
#include "ui/widgets/MathExpEvalWidget.h"

UiMathExpEval::UiMathExpEval(QWidget *parent) :
        QWidget(parent), ui(new Ui::UiMathExpEval)
{
    ui->setupUi(this);

    // Init math exp evaluator
    MathExpEvalWidget *math = new MathExpEvalWidget();
    this->ui->verticalLayout_Widget->addWidget(math);
}

UiMathExpEval::~UiMathExpEval()
{
    delete ui;
}

void UiMathExpEval::on_pushButton_NewWindow_clicked()
{
    QMainWindow *newWindow = new QMainWindow(this);

    // Init math exp evaluator
    MathExpEvalWidget *math = new MathExpEvalWidget(newWindow);

    // Set new window attributes
    newWindow->resize(math->size());
    newWindow->setAttribute(Qt::WA_DeleteOnClose);

    // Set MathExpEvalWidget as the central widget of the new window
    newWindow->setCentralWidget(math);

    // Show the new window
    newWindow->show();
}