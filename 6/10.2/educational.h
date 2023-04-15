#ifndef EDUCATIONAL_H
#define EDUCATIONAL_H


#include "film.h"
#include "entertainment.h"
#include <QString>

class Educational : public Film
{
private:
    QString m_Subject;
    int m_GradeLevel;
public:
    Educational(QString title, QString dir, QString len, QDate relDate, QString subject, int grdLvl);
    Educational(QStringList propList);
    QString toString(bool labeled, QString sepChar);
};

#endif // EDUCATIONAL_H
