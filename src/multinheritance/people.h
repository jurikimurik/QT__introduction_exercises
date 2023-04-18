#include "qdatetime.h"

class Person {
public:
    Person(QString name, QDate birthdate)
    QObject(name.ascii()),
    m_Birthdate(birthdate) {}

    Person(const Person& p) : QObject(p),
    m_Birthdate(p.m_Birthdate) {}

private:
    QDate m_Birthdate;
};

class Student : virtual public Person {       /* Zwróć uwagę na słowo kluczowe virtual. */
    // inne składowe
//end
//start
};

class Teacher : virtual public Person {       /* Wirtualne dziedziczenie. */
    // inne składowe
//end
//start
}


class GraduateTeachingFellow :
    public Student, public Teacher {          /* Słowo kluczowe virtual nie jest tutaj potrzebne. */
public:
    GraduateTeachingFellow(const Person& p,
                           const Student& s, const Teacher& t):
    Person(p), Students(s), Teacher(t) {}     /* Konieczna jest jawna inicjalizacja wszystkich wirtualnych klas bazowych w wielokrotnie dziedziczących klasach, 
		by nie pojawiły się niejasności dotyczące sposobu ich inicjalizacji. */
}

