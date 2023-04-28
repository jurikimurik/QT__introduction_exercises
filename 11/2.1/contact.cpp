#include "contact.h"

Contact::Contact(const QString &name, const QString &number, int category, const QString &zipCode) : m_name(name),
    m_number(number),
    m_category(category),
    m_zipCode(zipCode)
{}

QString Contact::name() const
{
    return m_name;
}

void Contact::setName(const QString &newName)
{
    m_name = newName;
}

QString Contact::number() const
{
    return m_number;
}

void Contact::setNumber(const QString &newNumber)
{
    m_number = newNumber;
}

int Contact::category() const
{
    return m_category;
}

void Contact::setCategory(int newCategory)
{
    m_category = newCategory;
}

QString Contact::zipCode() const
{
    return m_zipCode;
}

void Contact::setZipCode(const QString &newZipCode)
{
    m_zipCode = newZipCode;
}

QString Contact::toString() const
{
    return m_name + ": " + m_number + ", " + QString::number(m_category) + ", " + m_zipCode;
}
