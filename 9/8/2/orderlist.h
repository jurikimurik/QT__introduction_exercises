#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <QVector>
#include "order.h"

class OrderList : public QVector<Order>
{
private:
    double m_TotalPrice = 0;
public:
    OrderList();
    OrderList(QVector<Order> zamowienia);

    void addOrder(Order zamowienie);
    double getTotalPrice() const;

    QString toString() const;
};

#endif // ORDERLIST_H
