#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QDate>

class Order
{

private:
    QString m_Name;
    QDate m_Date;
    int m_Quantity;
    double m_Price;
    double m_TotalPrice;

public:
    explicit Order();
    explicit Order(QString name, QDate date, int quantity, double price);

    void setName(QString name);
    void setDate(QDate date);
    void setQuantity(int quantity);
    void setPrice(double price);

    double getTotalPrice() const;

    QString toString() const;
};

#endif // ORDER_H
