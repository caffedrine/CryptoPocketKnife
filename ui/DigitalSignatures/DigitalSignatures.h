#ifndef CRYPTOPOCKETKNIFE_DIGITALSIGNATURES_H
#define CRYPTOPOCKETKNIFE_DIGITALSIGNATURES_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui
{
    class DigitalSignatures;
}
QT_END_NAMESPACE

class DigitalSignatures : public QWidget
{
Q_OBJECT

public:
    explicit DigitalSignatures(QWidget *parent = nullptr);
    ~DigitalSignatures() override;

private:
    Ui::DigitalSignatures *ui;
};


#endif //CRYPTOPOCKETKNIFE_DIGITALSIGNATURES_H
