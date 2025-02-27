#include "MathExpEvalWidget.h"
#include "ui_MathExpEvalWidget.h"

// https://github.com/Blake-Madden/tinyexpr-plusplus
#include "tinyexpr.h"
#include <QUtils/QUtils.h>
#include <QWidgets/QWidgetsUtils.h>

#include <regex>
#include <sstream>

MathExpEvalWidget::MathExpEvalWidget(QWidget *parent): QWidget(parent), ui(new Ui::MathExpEvalWidget)
{
    ui->setupUi(this);
}

MathExpEvalWidget::~MathExpEvalWidget()
{
    delete ui;
}

// Function to convert hex to decimal
std::string hexToDecimal(const std::string& hex) {
    std::stringstream ss;
    ss << std::hex << hex; // Convert hex string to integer
    int decimalValue;
    ss >> decimalValue; // Store the decimal value
    return std::to_string(decimalValue);
}

void MathExpEvalWidget::on_plainTextEdit_MathExpInput_textChanged()
{
    te_parser tep;

    // Get raw input
    std::string input = this->ui->plainTextEdit_MathExpInput->toPlainText().toLower().trimmed().toStdString();

    // Regular expression to match hex numbers
    std::regex hexRegex("0x[0-9A-Fa-f]+");

    // Find each match and replace with its decimal equivalent
    std::sregex_iterator iter(input.begin(), input.end(), hexRegex);
    std::sregex_iterator end;
    while (iter != end)
    {
        std::smatch match = *iter;
        input.replace(match.position(), match.length(), hexToDecimal(match.str()));
        iter++;
    }

    auto evalResult = tep.evaluate(input);
    if( std::isnan(evalResult) )
    {
        this->ui->lineEdit_MathExpResult->setText("ERROR");
        return;
    }

    QString resultStr = QString::number(evalResult, 'g', 1024);
    this->ui->lineEdit_MathExpResult->setText(resultStr);
}
