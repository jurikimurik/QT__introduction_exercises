#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact(const QString &name, const QString &number, int category, const QString &zipCode);
    QString name() const;
    void setName(const QString &newName);
    QString number() const;
    void setNumber(const QString &newNumber);
    int category() const;
    void setCategory(int newCategory);
    QString zipCode() const;
    void setZipCode(const QString &newZipCode);

    QString toString() const;
private:
    QString m_name;
    QString m_number;
    int m_category;
    QString m_zipCode;
};

class CaseSortByCategory {
public:
    bool operator()(const Contact* first, const Contact* second) const {
        return first->category() < second->category();
    }
};

class CaseSortByZipCode {
public:
    bool operator()(const Contact* first, const Contact* second) const {
        int firstNumber = first->zipCode().remove('-').toInt();
        int secondNumber = second->zipCode().remove('-').toInt();
        return firstNumber < secondNumber;
    }
};

#endif // CONTACT_H
