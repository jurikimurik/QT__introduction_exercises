#ifndef RELATIONWINDOW_H
#define RELATIONWINDOW_H

#include <QMainWindow>
#include <QListView>
#include "relations.h"
#include <QAbstractTableModel>
#include <QInputDialog>

namespace Ui {
class RelationWindow;
}

class RelationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RelationWindow(QWidget *parent = nullptr);
    ~RelationWindow();

private slots:
    void somethingChanged();
    void addNewItem();

private:
    Ui::RelationWindow *ui;
    QListView* lewy;
    QListView* prawy;

    Relations* relation;
};

#endif // RELATIONWINDOW_H
