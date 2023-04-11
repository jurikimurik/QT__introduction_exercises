#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Position;

class Person
{
private:
    QString m_Name;
    bool m_Employed;
    Position* m_Position;
public:
    Person(QString imie = "Brak osoby.", bool employed = false) : m_Name(imie), m_Employed(employed) {}

    QString getName() {
        return m_Name;
    }

    Position* getPosition() {
        if(m_Employed) {
            return m_Position;
        } else {
            return nullptr;
        }
    }

    void setEmployed(bool isEmployed) {
        m_Employed = isEmployed;
    }



    bool apply(Position* position);
};

#endif // PERSON_H
