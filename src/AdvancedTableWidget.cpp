#include "AdvancedTableWidget.h"

AdvancedTableWidget::AdvancedTableWidget(QWidget *parent): QTableWidget(parent)
{
    this->AdvancedTableWidgetInit();
}

AdvancedTableWidget::AdvancedTableWidget(int rows, int columns, QWidget *parent): QTableWidget(rows, columns, parent)
{
    this->AdvancedTableWidgetInit();
}

void AdvancedTableWidget::AdvancedTableWidgetInit()
{
    this->setAcceptDrops(true);
}

void AdvancedTableWidget::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls())
    {
        e->acceptProposedAction();
    }
}

void AdvancedTableWidget::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls())
    {
        QString fileName = url.toLocalFile();
        emit OnDraggedFile(fileName);
    }
}
