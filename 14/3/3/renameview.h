#ifndef RENAMEVIEW_H
#define RENAMEVIEW_H

#include <QMainWindow>

namespace Ui {
class RenameView;
}

class RenameView : public QMainWindow
{
    Q_OBJECT

public:
    explicit RenameView(QWidget *parent = nullptr);
    ~RenameView();

private:
    Ui::RenameView *ui;
};

#endif // RENAMEVIEW_H
