#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeWidget>
#include <QTableWidget>

namespace Ui {
class FileExplorer;
}

class FileExplorer : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileExplorer(QWidget *parent = nullptr);
    ~FileExplorer();

private:
    Ui::FileExplorer *ui;
    QFileSystemModel *m_Model;

    QTreeWidget *tree;
    QTableWidget *table;
};

#endif // FILEEXPLORER_H
