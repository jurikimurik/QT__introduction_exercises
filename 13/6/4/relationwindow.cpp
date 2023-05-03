#include "relationwindow.h"
#include "ui_relationwindow.h"

#include <QDebug>

RelationWindow::RelationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RelationWindow),
    relation(new Relations(this))
{
    ui->setupUi(this);
    lewy =  ui->listView;
    prawy = ui->listView_2;

    lewy->setModel(relation);
    lewy->setModelColumn(0);
    lewy->setSelectionRectVisible(true);

    prawy->setModel(relation);
    prawy->setModelColumn(1);
    prawy->setSelectionRectVisible(true);

    connect(lewy, &QListView::clicked, relation, &Relations::showRelation);
    connect(relation, &QAbstractTableModel::dataChanged, this, &RelationWindow::somethingChanged);
}

RelationWindow::~RelationWindow()
{
    delete ui;
}

void RelationWindow::somethingChanged()
{
    qDebug() << "Cos sie zmienilo...";
}
