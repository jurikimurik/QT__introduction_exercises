#include "order.h"

Order::Order(QObject* parent) : QObject(parent)
{}

Order::Order(QString name, QDate date, int quantity, double price, QObject *parent) :
    QObject(parent), m_Name(name), m_Date(date), m_Quantity(quantity), m_Price(price),
    m_TotalPrice(quantity*price)
{}


void Order::setName(QString name) {
    m_Name = name;
}

void Order::setDate(QDate date) {
    m_Date = date;
}

void Order::setQuantity(int quantity) {
    m_Quantity = quantity;
}

void Order::setPrice(double price) {
    m_Price = price;

    m_TotalPrice = m_Quantity * m_Price;
}

QString Order::toString() const {
    return QString("\"%1\", %2, ilosc: %3, %4 $ za sztuke. Za calosc: %5 $").arg(m_Name).arg(m_Date.toString("yyyy/MM/dd"))
        .arg(QString::number(m_Quantity)).arg(QString::number(m_Price)).arg(QString::number(m_TotalPrice));
}
