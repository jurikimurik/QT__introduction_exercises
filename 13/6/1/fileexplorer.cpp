#include "fileexplorer.h"
#include "ui_fileexplorer.h"

FileExplorer::FileExplorer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileExplorer)
{
    ui->setupUi(this);
    tree =  ui->centralwidget->findChild<QTreeView*>("treeView");
    table = ui->centralwidget->findChild<QTableView*>("tableView");
    box = ui->centralwidget->findChild<QComboBox*>("comboBox");

    m_Model = new QFileSystemModel(this);
    m_Model->setRootPath("/");

    tree->setModel(m_Model);
    tree->setSortingEnabled(true);
    tree->hideColumn(1);
    tree->hideColumn(2);
    tree->hideColumn(3);
    tree->hideColumn(4);


    table->setModel(m_Model);
    table->setSelectionModel(tree->selectionModel());
    table->setSortingEnabled(true);
    table->setColumnWidth(0, 200);
    table->setColumnWidth(1, 100);
    table->setColumnWidth(2, 50);
    table->setColumnWidth(3, 200);
}

FileExplorer::~FileExplorer()
{
    delete ui;
}

void FileExplorer::updateAddress(const QModelIndex &index)
{
    qDebug() << "FileExplorer::updateAddress(QModelIndex index)";
    qDebug() << index.data().toString();
    box->clear();
    box->addItem(m_Model->filePath(index));
}

void FileExplorer::on_treeView_doubleClicked(const QModelIndex &index)
{
    qDebug() << "FileExplorer::on_treeView_doubleClicked(const QModelIndex &index)";
    qDebug() << m_Model->fileName(index);
}


void FileExplorer::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug() << "FileExplorer::on_tableView_doubleClicked(const QModelIndex &index)";
}

void FileExplorer::moveUp()
{
    qDebug() << "FileExplorer::moveUp()";
}



