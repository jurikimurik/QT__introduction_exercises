#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H

#include <QTableView>

/** Widok listy nagrań do odtworzenia, zaimplementowany jako model tablicowy. 
    Promocja z QTableView w MainWindow.ui
*/
class PlayListView : public QTableView {
    Q_OBJECT
public:
    explicit PlayListView(QWidget* parent=0);
    virtual void dropEvent(QDropEvent* event);
    virtual void startDrag(Qt::DropActions supportedActions);

};


#endif        //  #ifndef PLAYLISTVIEW_H

