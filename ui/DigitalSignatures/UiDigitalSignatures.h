#ifndef CRYPTOPOCKETKNIFE_UIDIGITALSIGNATURES_H
#define CRYPTOPOCKETKNIFE_UIDIGITALSIGNATURES_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class UiDigitalSignatures;
}
QT_END_NAMESPACE

class UiDigitalSignatures : public QWidget
{
Q_OBJECT

public:
    explicit UiDigitalSignatures(QWidget *parent = nullptr);
    ~UiDigitalSignatures() override;

private:
    Ui::UiDigitalSignatures *ui;
};


#endif //CRYPTOPOCKETKNIFE_UIDIGITALSIGNATURES_H
