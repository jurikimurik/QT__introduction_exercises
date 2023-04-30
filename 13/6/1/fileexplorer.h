#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include <QComboBox>

#include <QDebug>
#include <thread>
#include <chrono>

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
    void updateAddress();
    void updateAddressOnLoad(const QString &path);

private slots:
    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void moveUp();

    void goTo(const QString &path);
private:
    QString indexToPath(const QModelIndex &index);

private:
    Ui::FileExplorer *ui;
    QFileSystemModel *m_Model;

    QTreeView *tree;
    QTableView *table;

    QComboBox *box;
};

#endif // FILEEXPLORER_H
