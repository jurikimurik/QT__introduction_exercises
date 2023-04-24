#include "handview.h"
#include "ui_handview.h"

#include <QDebug>

HandView::HandView(QWidget *parent) :
    QWidget(parent),
    m_karty(new Hand()),
    ui(new Ui::HandView)
{
    ui->setupUi(this);
}

HandView::~HandView()
{
    delete ui;
}

void HandView::setModel(Hand *hand)
{
    delete m_karty;
    m_karty = hand;
}

int HandView::getValue()
{
    int suma = 0;
    for(const auto& elem: *m_karty)
    {
        suma += elem->value();
    }
    return suma;
}

void HandView::addCard(Card* karta)
{
    *m_karty << karta;
    karta->label()->setObjectName("label");

    ui->groupBox->layout()->addWidget(karta->label());
}

void HandView::clearHand()
{
    for(auto elem : ui->groupBox->children())
    {
        if(elem->objectName().indexOf("label") != -1)
                elem->deleteLater();
    }

    m_karty->clearHand();
}
