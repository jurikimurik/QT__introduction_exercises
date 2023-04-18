//start id="student"
#include <QTextStream>
#include "student.h"

Student::Student(QString nm, long id, QString major, int year)
        : m_Name(nm), m_Major(major), m_StudentId(id), m_Year(year) {}


QString Student::getClassName() const {
    return "Student";
}

QString Student::toString() const {
    QString retval;
    QTextStream os(&retval);                /* Zapisz do strumienia i zwróć łańcuch znaków.*/
    os << "[" << getClassName() << "]" 
         << " nazwisko: " << m_Name
         << "; id: " << m_StudentId
         << "; rok: " << yearStr()
         << "; \nkierunek: " << m_Major  ;
    return retval;

}
//end

QString Student::yearStr() const {
    switch(m_Year) {
    case 1:
        return "1";
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "dinozaur";
    }
    return "nieznany";
}

//start id="undergrad"
Undergrad::Undergrad(QString name, long id, QString major, 
      int year, int sat)
: Student(name, id, major, year), m_SAT(sat)  /* Obiekt klasy bazowej jest traktowany jako podobiekt
			obiektu pochodnego. Składowe klasy i jej klasy bazowe muszą zostać zainicjalizowane 
			w kolejności, w jakiej pojawiają się w definicji klasy. */
   { }

QString Undergrad::getClassName() const {
    return "Undergrad";
}

QString Undergrad::toString() const {
    QString result;
    QTextStream os(&result);
    os <<  Student::toString()                /* Wywołanie wersji funkcji zdefiniowanej w klasie bazowej. */
       << "  [SAT: "                          /* Dodanie elementów specyficznych dla Undergrad. */
       << m_SAT
       << " ]\n";
    return result;
}
//end

//start id="grad"
GradStudent::
GradStudent(QString nm, long id, QString major, int yr, 
                   Support support) :Student(nm, id, major, yr), 
            m_Support(support) { }

QString GradStudent::toString() const {       /* Zwracamy wartość typu QString. */
   return QString("%1%2%3 ]\n")
       .arg(Student::toString())              /* Wywołanie wersji z klasy bazowej. */
       .arg("  [Stypendium: ")                   /* Dodanie elementów specyficznych dla klasy GradStudent. */ 
       .arg(supportStr(m_Support));
}
//end

QString GradStudent::supportStr(Support sup) {
    switch(sup) {                             /* Use enumerators for case labels. */
    case ta:
        return "ta";
    case ra:
        return "ra";
    case fellowship:
        return "drużyna";
    case other:
        return "inne";
    }
    return "nieznane";
}
QString GradStudent::getClassName() const {
    return "GradStudent";
}

