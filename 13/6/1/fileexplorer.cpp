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

    connect(m_Model, &QFileSystemModel::directoryLoaded, this, &FileExplorer::updateAddressOnLoad);
}

FileExplorer::~FileExplorer()
{
    delete ui;
}

void FileExplorer::updateAddress()
{
    qDebug() << "FileExplorer::updateAddress(QModelIndex index)";
    box->clear();
    QModelIndex index = tree->currentIndex();
    box->addItem(m_Model->filePath(index));

    int rowsNumber = m_Model->rowCount(index);
    for(int i = 0; i < rowsNumber; ++i)
    {
        QModelIndex child = m_Model->index(i, 0, index);
        if(m_Model->isDir(child))
            box->addItem(m_Model->filePath(child));
    }
}

void FileExplorer::updateAddressOnLoad(const QString &path)
{
    qDebug() << "FileExplorer::updateAddressOnLoad(const QString &path)";
    box->clear();
    QModelIndex index = m_Model->index(path);
    box->addItem(m_Model->filePath(index));


    int rowsNumber = m_Model->rowCount(index);
    for(int i = 0; i < rowsNumber; ++i)
    {
        QModelIndex child = m_Model->index(i, 0, index);
        if(m_Model->isDir(child))
            box->addItem(m_Model->filePath(child));
    }
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
    tree->collapse(tree->currentIndex().parent());
}



