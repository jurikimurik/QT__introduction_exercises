#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>

#include <QDebug>

namespace Ui {
class FileExplorer;
}

class FileExplorer : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileExplorer(QWidget *parent = nullptr);
    ~FileExplorer();

public slots:
    void updateAddress(QModelIndex index);

private slots:
    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::FileExplorer *ui;
    QFileSystemModel *m_Model;

    QTreeView *tree;
    QTableView *table;
};

#endif // FILEEXPLORER_H
