#ifndef PLAYLISTWINDOW_H
#define PLAYLISTWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>
#include "playlistmodel.h"
#include <QDataStream>

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
    void savePlaylist();
    void loadPlaylist();

private:
    Ui::PlayListWindow *ui;

    QMediaPlayer *m_player;
    PlayListModel* m_model = nullptr;
};

#endif // PLAYLISTWINDOW_H
