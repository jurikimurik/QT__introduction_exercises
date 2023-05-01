#include "playlistwindow.h"
#include "ui_playlistwindow.h"

#include <QDebug>

PlayListWindow::PlayListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayListWindow)
{
    ui->setupUi(this);
}

PlayListWindow::~PlayListWindow()
{
    delete ui;
}

void PlayListWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this);
    qDebug() << path;
}

