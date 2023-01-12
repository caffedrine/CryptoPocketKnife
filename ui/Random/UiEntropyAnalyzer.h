//
// Created by uib74520 on 2023-01-12.
//

#ifndef CRYPTOPOCKETKNIFE_UIENTROPYANALYZER_H
#define CRYPTOPOCKETKNIFE_UIENTROPYANALYZER_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class UiEntropyAnalyzer;
}
QT_END_NAMESPACE

class UiEntropyAnalyzer : public QMainWindow
{
Q_OBJECT

public:
    explicit UiEntropyAnalyzer(QWidget *parent = nullptr);
    ~UiEntropyAnalyzer() override;

private:
    Ui::UiEntropyAnalyzer *ui;

protected slots:
    void on_pushButton_AnalyzeInput_clicked();
    void on_pushButton_LoadFiles_clicked();
    void OnRawDataFileDragged(QString filename);
};


#endif //CRYPTOPOCKETKNIFE_UIENTROPYANALYZER_H
