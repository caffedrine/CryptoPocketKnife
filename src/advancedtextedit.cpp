#include "advancedtextedit.h"

AdvancedTextEdit::AdvancedTextEdit(QWidget *parent): QTextEdit(parent)
{
    this->setAcceptDrops(true);
}

AdvancedTextEdit::AdvancedTextEdit(const QString &text, QWidget *parent): QTextEdit(text, parent)
{
    this->setAcceptDrops(true);
}

void AdvancedTextEdit::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls())
    {
        e->acceptProposedAction();
    }
}

void AdvancedTextEdit::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls())
    {
        QString fileName = url.toLocalFile();
        emit OnDraggedFile(fileName);
    }
}