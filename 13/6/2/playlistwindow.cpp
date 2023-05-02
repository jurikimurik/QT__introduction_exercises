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
    if(m_model != nullptr)
        delete m_model;
    m_model = new PlayListModel(list, this);
    connect(m_model, &QAbstractTableModel::dataChanged, ui->tableView, &QTableView::reset);

    ui->tableView->setModel(m_model);
}

void PlayListWindow::savePlaylist()
{
    QString fileToSave = QFileDialog::getSaveFileName(this);
    QFile plik(fileToSave);
    if(!plik.open(QIODevice::WriteOnly))
        return;

    QDataStream out(&plik);
    for(auto& elem: m_model->objects())
    {
        out << elem[elem.Title] << elem[elem.MediaType] << elem[elem.Duration];
    }
    plik.close();
}

void PlayListWindow::loadPlaylist()
{
    QString fileToLoad = QFileDialog::getOpenFileName(this);
    QFile plik(fileToLoad);
    if(!plik.open(QIODevice::ReadOnly))
        return;

    QList<QMediaMetaData> lista;
    QDataStream in(&plik);
    while(!in.atEnd())
    {

        qDebug() << "CZYTAM";
        QMediaMetaData data;

        in >> data[data.Title] >> data[data.MediaType] >> data[data.Duration];

        qDebug() << data.stringValue(data.Title);
        lista.push_back(data);
    }

    if(m_model != nullptr)
        delete m_model;
    m_model = new PlayListModel(lista, this);
    connect(m_model, &QAbstractTableModel::dataChanged, ui->tableView, &QTableView::reset);

    ui->tableView->setModel(m_model);
}

