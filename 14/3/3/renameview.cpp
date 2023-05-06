#include "renameview.h"
#include "ui_renameview.h"

RenameView::RenameView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenameView)
{
    ui->setupUi(this);
}

RenameView::~RenameView()
{
    delete ui;
}
