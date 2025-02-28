#ifndef CRYPTOPOCKETKNIFE_UIDOMAINWHOIS_H
#define CRYPTOPOCKETKNIFE_UIDOMAINWHOIS_H

#include <QWidget>
#include "DomainWhois/DomainWhois.h"

#include "extensions/AdvancedTextEdit.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiDomainWhois;
}
QT_END_NAMESPACE

class UiDomainWhois : public QWidget
{
Q_OBJECT

public:
    explicit UiDomainWhois(QWidget *parent = nullptr, QString domain = "");
    ~UiDomainWhois() override;
    void TriggerWhois() {this->on_pushButton_Lookup_clicked();};

protected slots:
    void on_pushButton_Lookup_clicked();

private:
    Ui::UiDomainWhois *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIDOMAINWHOIS_H
