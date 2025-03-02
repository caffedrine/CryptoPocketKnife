#ifndef ADVANCEDTEXTEDIT_H
#define ADVANCEDTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>

#if !defined(DLL_DECL_SPEC)
#define DLL_DECL_SPEC
#endif

class DLL_DECL_SPEC AdvancedTextEdit: public QTextEdit
{
    Q_OBJECT
public:
    explicit AdvancedTextEdit(QWidget *parent = nullptr);
    explicit AdvancedTextEdit(const QString &text, QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

signals:
    void OnDraggedFile(QString filename);

private:
    void AdvancedTextEditInit();
};

#endif // ADVANCEDTEXTEDIT_H
