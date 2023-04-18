#ifndef PLAYLISTSVIEW_H
#define PLAYLISTSVIEW_H

#include <QListView>


/** Widok listy list odtwarzania
    (w tym wypadku SourceListModel)
    Promowany z QListView w mainwindow.ui
*/
class PlaylistsView : public QListView {
public:
    PlaylistsView(QWidget* parent=0) : QListView(parent) {
        /* Inicjalizowany z MainWindow.ui jako widżet promowany. */
    }
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
};

#endif // PLAYLISTSVIEW_H

