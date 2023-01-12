#ifndef CRYPTOPOCKETKNIFE_UIRANDOM_H
#define CRYPTOPOCKETKNIFE_UIRANDOM_H

#include <QWidget>
#include "UiEntropyAnalyzer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class UiRandom;
}
QT_END_NAMESPACE

class UiRandom : public QWidget
{
Q_OBJECT

public:
    explicit UiRandom(QWidget *parent = nullptr);
    ~UiRandom() override;

private:
    Ui::UiRandom *ui;
    UiEntropyAnalyzer *entropyAnalyzer;

};


#endif //CRYPTOPOCKETKNIFE_UIRANDOM_H
