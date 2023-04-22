#include "ui_ksl.h"

#include <QDebug>

ui_keysequencelabel::ui_keysequencelabel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ui_keysequencelabel)
{
    ui->setupUi(this);
}

ui_keysequencelabel::~ui_keysequencelabel()
{
    delete ui;
}

void ui_keysequencelabel::on_m_clearButton_clicked()
{
    qDebug() << "OCZYSZCZAM" << Qt::flush;
}

void ui_keysequencelabel::on_actionQuit_triggered()
{
    qDebug() << "WYCHODZE" << Qt::flush;
}

void ui_keysequencelabel::on_actionShow_ObjectBrowser_triggered(bool checked)
{
    qDebug() << "UPDATE" << Qt::flush;
}
