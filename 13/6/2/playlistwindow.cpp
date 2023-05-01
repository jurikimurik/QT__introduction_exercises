#include "playlistwindow.h"
#include "ui_playlistwindow.h"

#include <QDebug>

PlayListWindow::PlayListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayListWindow)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer(this);

}

PlayListWindow::~PlayListWindow()
{
    delete ui;
}

void PlayListWindow::on_pushButton_clicked()
{
    QList<QMediaMetaData> list;

    QStringList pathList = QFileDialog::getOpenFileNames(this);
    for(int i = 0; i < pathList.size(); ++i)
    {
        QString path = pathList.at(i);
        QEventLoop loop;
        connect(m_player, &QMediaPlayer::metaDataChanged, &loop, &QEventLoop::quit);
        m_player->setSource(QUrl::fromLocalFile(path));
        loop.exec();



        list.push_back(m_player->metaData());
    }

    for(const auto& elem :list)
    {
        qDebug() << elem.stringValue(QMediaMetaData::Title);
    }

    qDebug() << "KONIEC";
}

