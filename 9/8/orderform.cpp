#include "orderform.h"
/* Musisz zaimplementować brakujące metody w tym pliku */

#include <QDebug>

#include "order.h"

OrderForm::OrderForm(QWidget *parent) : QWidget(parent), m_nameEdit(new QLineEdit(this)), m_dateEdit(new QDateEdit(this)),
    m_quantitySpin(new QSpinBox(this)), m_submitButton(new QPushButton(this)), m_cancelButton(new QPushButton(this))
{
    auto layout = new QFormLayout(this);

    layout->addRow("Nazwa: ", m_nameEdit);

    m_dateEdit->setDate(QDate::currentDate());
    layout->addRow("Data dodania: ", m_dateEdit);

    layout->addRow("Ilosc: ", m_quantitySpin);

    auto doubleSpinBox = new QDoubleSpinBox(this);
    doubleSpinBox->setObjectName("CJ");
    layout->addRow("Cena jednostki: ", doubleSpinBox);

    auto totalDoubleSpinBox = new QDoubleSpinBox(this);
    totalDoubleSpinBox->setObjectName("TP");
    totalDoubleSpinBox->setEnabled(false);
    layout->addRow("Cena calkowita: ", totalDoubleSpinBox);

    m_submitButton->setText("Ok");
    m_submitButton->connect(m_submitButton, &QPushButton::pressed, this, &OrderForm::submit);
    layout->addWidget(m_submitButton);

    m_cancelButton->setText("Anuluj");
    m_cancelButton->connect(m_cancelButton, &QPushButton::pressed, this, &OrderForm::cancel);
    layout->addWidget(m_cancelButton);

    for(int i = 0; i < layout->count(); ++i)
    {
        layout->itemAt(i)->widget()->setMinimumWidth(100);
    }

    setLayout(layout);
}

void OrderForm::submit()
{
    auto totalPriceWidget = findChild<QDoubleSpinBox*>("TP");
    auto unitPriceWidget = findChild<QDoubleSpinBox*>("CJ");

    double cena = m_quantitySpin->value() * unitPriceWidget->value();
    totalPriceWidget->setValue(totalPriceWidget->value() + cena);

    m_Order->setName(m_nameEdit->text());
    m_Order->setDateAdded(m_dateEdit->date());
    m_Order->setQuantity(m_quantitySpin->value());
    m_Order->setPrice(findChild<QDoubleSpinBox*>("TP")->value());
}

void OrderForm::cancel()
{
    m_nameEdit->setText(QString());
    m_dateEdit->setDate(QDate::currentDate());
    m_quantitySpin->setValue(0);

    auto unitPriceWidget = findChild<QDoubleSpinBox*>("CJ");
    unitPriceWidget->setValue(0);
}

void OrderForm::setOrder(Order *prod) {
    m_Order = prod;
}
