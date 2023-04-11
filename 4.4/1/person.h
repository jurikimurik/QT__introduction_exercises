#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
private:
    QString m_Name;
    bool m_Employed;
public:
    Person(QString imie = "Brak osoby.", bool employed = false) : m_Name(imie), m_Employed(employed) {}

    QString getName() {
        return m_Name;
    }

    void setEmployed(bool isEmployed) {
        m_Employed = isEmployed;
    }
};

#endif // PERSON_H
