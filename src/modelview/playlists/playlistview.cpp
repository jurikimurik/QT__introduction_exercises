#include <QtGui>
#include "playlistview.h"
#include "mainwindow.h"

PlayListView::PlayListView(QWidget* parent) : QTableView(parent) {
    /* Uwaga: To widżet promowany, część jego inicjalizacji odbywa się w MainWindow.ui. */

    QHeaderView* hv = horizontalHeader();
    hv->setResizeMode(QHeaderView::ResizeToContents);

    /* Dodanie akcji z głównego okna */
    MainWindow* mw = MainWindow::instance();
    addAction(mw->actionCopy);
    addAction(mw->actionPaste);
    addAction(mw->actionCut);
    addAction(mw->actionRemove);
    addAction(mw->actionRefresh);
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

void PlayListView::dropEvent(QDropEvent* event) {
    model()->dropMimeData(event->mimeData(), event->dropAction(), -1, -1, QModelIndex());
    event->accept();
}

void PlayListView::startDrag(Qt::DropActions supportedActions) {
//    QTableView::startDrag(supportedActions);
    QModelIndexList indexes = selectionModel()->selectedRows();
    if (indexes.count() > 0) {
        QMimeData *data = model()->mimeData(indexes);
        if (!data)
            return;
        QDrag *drag = new QDrag(this);
        drag->setMimeData(data);
        Qt::DropAction defaultDropAction = Qt::IgnoreAction;
        drag->exec(supportedActions, defaultDropAction);
    }
}

