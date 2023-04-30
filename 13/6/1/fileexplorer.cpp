#include "fileexplorer.h"
#include "ui_fileexplorer.h"

FileExplorer::FileExplorer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileExplorer)
{
    ui->setupUi(this);
    tree =  ui->centralwidget->findChild<QTreeView*>("treeView");
    table = ui->centralwidget->findChild<QTableView*>("tableView");

    m_Model = new QFileSystemModel(this);
    m_Model->setRootPath("/");

    tree->setModel(m_Model);
    tree->setSortingEnabled(true);

    table->setModel(m_Model);
    table->setSelectionModel(tree->selectionModel());
    table->setColumnWidth(0, 200);
    table->setColumnWidth(1, 100);
    table->setColumnWidth(2, 50);
    table->setColumnWidth(3, 200);
}

FileExplorer::~FileExplorer()
{
    delete ui;
}

void FileExplorer::updateAddress(QModelIndex index)
{
    qDebug() << "FileExplorer::updateAddress(QModelIndex index)";
}

void FileExplorer::on_treeView_doubleClicked(const QModelIndex &index)
{
    qDebug() << "FileExplorer::on_treeView_doubleClicked(const QModelIndex &index)";
}


void FileExplorer::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug() << "FileExplorer::on_tableView_doubleClicked(const QModelIndex &index)";
}

