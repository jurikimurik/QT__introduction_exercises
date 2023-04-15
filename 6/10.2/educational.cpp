#include "educational.h"

Educational::Educational(QString title, QString dir, QString len, QDate relDate, QString subject, int grdLvl)
    : Film(QString(), title, dir, len.toInt(), relDate), m_Subject(subject), m_GradeLevel(grdLvl) {}

Educational::Educational(QStringList propList)
    : Film(propList.at(0), propList.at(1), propList.at(2), propList.at(3).toInt(), QDate::fromString(propList.at(4)))
{
    m_Subject = propList.at(5);
    m_GradeLevel = propList.at(6).toInt();
}

QString Educational::toString(bool labeled, QString sepChar)
{
    QString nazwa = Film::toString(labeled, sepChar);
    nazwa += sepChar + m_Subject + sepChar + QString::number(m_GradeLevel);
    return nazwa;
}
