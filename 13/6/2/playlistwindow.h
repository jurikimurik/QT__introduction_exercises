#ifndef PLAYLISTWINDOW_H
#define PLAYLISTWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "playlistmodel.h"

namespace Ui {
class PlayListWindow;
}

class PlayListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayListWindow(QWidget *parent = nullptr);
    ~PlayListWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PlayListWindow *ui;

    PlayListModel* m_model;
};

#endif // PLAYLISTWINDOW_H
