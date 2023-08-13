#ifndef CRYPTOPOCKETKNIFE_AUTHENTICATEDENCRYPTION_H
#define CRYPTOPOCKETKNIFE_AUTHENTICATEDENCRYPTION_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class AuthenticatedEncryption;
}
QT_END_NAMESPACE

class AuthenticatedEncryption : public QMainWindow
{
Q_OBJECT

public:
    explicit AuthenticatedEncryption(QWidget *parent = nullptr);
    ~AuthenticatedEncryption() override;

private:
    Ui::AuthenticatedEncryption *ui;
};


#endif //CRYPTOPOCKETKNIFE_AUTHENTICATEDENCRYPTION_H
