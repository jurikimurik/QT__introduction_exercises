#include "student.h"
#include <QTextStream>

Student::Student(QString nm, long id, QString major, int year)
    : m_Name(nm), m_Major(major), m_StudentId(id), m_Year(year) {}

QString Student::getClassName() const {
    return "Student";
}

QString Student::toString() const {
    QString retval;
    QTextStream os(&retval);
    os << "[" << getClassName() << "]"
       << " nazwisko: " << m_Name
       << "; id: " << m_StudentId
       << "; rok: " << yearStr()
       << "; \nkierunek: " << m_Major;
    return retval;
}

QString Student::yearStr() const {
    return QString::number(m_Year);
}

Undergrad::Undergrad(QString name, long id, QString major, int year, int sat)
    : Student(name, id, major, year), m_SAT(sat) {}

QString Undergrad::getClassName() const {
    return "Licencjat";
}

QString Undergrad::toString() const {
    QString result;
    QTextStream os(&result);
    os << Student::toString()
       << " [SAT: "
       << m_SAT
       << " ]\n";
    return result;
}

GradStudent::GradStudent(QString nm, long id, QString major, int yr, Support support)
    : Student(nm, id, major, yr), m_Support(support) {}

QString GradStudent::toString() const {
    return QString("%1%2%3 ]\n").arg(Student::toString()).arg(" [stypendium: ").arg(supportStr(m_Support));
}

QString GradStudent::supportStr(Support sup) {
    QString stypendia_text;

    switch(sup)
    {
    case Support::ra: stypendia_text = QString::fromStdString("Socjalne"); break;
    case Support::ta: stypendia_text = QString::fromStdString("Rektorskie");break;
    case Support::fellowship: stypendia_text = QString::fromStdString("Zagraniczne"); break;
    case Support::other: stypendia_text = QString::fromStdString("Inne"); break;
    }

    return stypendia_text;
}
