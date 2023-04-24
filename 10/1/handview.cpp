#include "handview.h"
#include "ui_handview.h"

#include <QDebug>

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

void HandView::addCard()
{
    auto label = new QLabel("Tu bedzie karta", ui->groupBox);
    label->setObjectName("label");

    ui->groupBox->layout()->addWidget(label);
}

void HandView::clearHand()
{
    ui->groupBox->dumpObjectTree();
    for(auto elem : ui->groupBox->children())
    {
        if(elem->objectName().indexOf("label") != -1)
                elem->deleteLater();
    }
}
