#include "orderlist.h"

OrderList::OrderList() {}

OrderList::OrderList(QVector<Order> zamowienia) {
    for(const auto& elem : zamowienia)
    {
        addOrder(elem);
    }
}

void OrderList::addOrder(Order zamowienie) {

    m_TotalPrice += zamowienie.getTotalPrice();
    push_back(zamowienie);
}

double OrderList::getTotalPrice() const {
    return m_TotalPrice;
}

QString OrderList::toString() const {
    QString str;
    for(const auto& elem : *this)
    {
        str += elem.toString() + "\n";
    }
    str += "Calkowita wartosc zamowienia: " + QString::number(getTotalPrice()) + "\n";
    return str;
}
