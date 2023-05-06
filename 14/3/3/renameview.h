#ifndef RENAMEVIEW_H
#define RENAMEVIEW_H

#include <QMainWindow>
#include <QFileDialog>
#include "renamemodel.h"

namespace Ui {
class RenameView;
}

class RenameView : public QMainWindow
{
    Q_OBJECT

public:
    explicit RenameView(QWidget *parent = nullptr);
    ~RenameView();

public slots:
    void loadPath();
    void generate();

private:
    Ui::RenameView *ui;
    QDir m_directory;
};

#endif // RENAMEVIEW_H
