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
    int ilosc_asow = 0;
    for(const auto& elem: *m_karty)
    {
        if(elem->isAce())
            ilosc_asow++;
        else
            suma += elem->value();
    }

    //Uwzgledniamy asy w najlepszym dopasowaniu
    for(int i = 0; i < ilosc_asow; ++i)
    {
        if(suma + 11 <= 21)
            suma += 11;
        else
            suma += 1;
    }

    qDebug() << suma << Qt::endl;

    return suma;
}

Hand *HandView::getHand()
{
    return m_karty;
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
