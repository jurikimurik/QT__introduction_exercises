#ifndef RELATIONWINDOW_H
#define RELATIONWINDOW_H

#include <QMainWindow>
#include "relations.h"

namespace Ui {
class RelationWindow;
}

class RelationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RelationWindow(QWidget *parent = nullptr);
    ~RelationWindow();

private:
    Ui::RelationWindow *ui;
};

#endif // RELATIONWINDOW_H
