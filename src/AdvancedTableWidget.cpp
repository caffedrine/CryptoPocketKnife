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

    this->verticalHeader()->setVisible(false);
    this->setSortingEnabled(true);
    this->setSelectionBehavior(SelectionBehavior::SelectRows);
    this->installEventFilter(this);

    QString styleSheet = "::section "
                         "{"
                                "background-color: #edf0f5;"
                         "}";
    this->horizontalHeader()->setStyleSheet(styleSheet);

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

void AdvancedTableWidget::keyPressEvent(QKeyEvent *event)
{
    QModelIndexList selectedRows = this->selectionModel()->selectedRows();

    // Delete selected row
    if(event->key() == Qt::Key_Delete)
    {
        if( !selectedRows.isEmpty() )
        {
            model()->removeRows(selectedRows.at(0).row(), selectedRows.size());
        }
    }

    // Copy selected row
    else if(event->matches(QKeySequence::Copy))
    {
        if(!selectedIndexes().isEmpty())
        {
            QString text;
            QItemSelectionRange range = selectionModel()->selection().first();
            for (auto i = range.top(); i <= range.bottom(); ++i)
            {
                QStringList rowContents;
                for (auto j = range.left(); j <= range.right(); ++j)
                    rowContents << model()->index(i,j).data().toString();
                text += rowContents.join("\t");
                text += "\n";
            }
            QApplication::clipboard()->setText(text);
        }
    }

    // Paste from clipboard
    else if(event->matches(QKeySequence::Paste))
    {
        QString text = QApplication::clipboard()->text();
        emit this->OnTextPasted(text);
    }

    // Send to default handler
    else
    {
        QTableView::keyPressEvent(event);
    }
}
