#include "handview.h"
#include "ui_handview.h"

HandView::HandView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HandView)
{
    ui->setupUi(this);
}

HandView::~HandView()
{
    delete ui;
}
