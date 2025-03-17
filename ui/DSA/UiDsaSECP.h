#ifndef CRYPTOPOCKETKNIFE_UIDSASECP_H
#define CRYPTOPOCKETKNIFE_UIDSASECP_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class UiDsaSECP; }
QT_END_NAMESPACE

struct UiDsaSecp_CurrAlgo
{
    UiDsaSecp_CurrAlgo() = default;
    UiDsaSecp_CurrAlgo(QString name, quint32 privKeySizeBytes, quint32 pubKeySizeBytes, int keyId) :
            name(std::move(name)), pubKeySizeBytes(pubKeySizeBytes), privKeySizeBytes(privKeySizeBytes), algoId(keyId) {};

    QString name = "";
    quint32 privKeySizeBytes = 0;
    quint32 pubKeySizeBytes = 0;
    int algoId = -1;
};

class UiDsaSECP : public QWidget
{
Q_OBJECT

public:
    explicit UiDsaSECP(QWidget *parent = nullptr);
    ~UiDsaSECP() override;

private slots:
    void on_textEdit_privateKey_textChanged(const QString &arg1);
    void on_textEdit_publicKey_textChanged(const QString &arg1);

    void on_pushButton_GenerateKeysPair_clicked();
    void on_pushButton_Keys_Clear_clicked();

    void on_pushButton_CalculateSignature_clicked();
    void on_pushButton_VerifySignature_clicked();

    void on_comboBox_AlgoName_currentTextChanged();

private:
    Ui::UiDsaSECP *ui;
    UiDsaSecp_CurrAlgo currAlgo;
};


#endif //CRYPTOPOCKETKNIFE_UIDSASECP_H
