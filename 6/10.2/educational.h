#ifndef EDUCATIONAL_H
#define EDUCATIONAL_H


#include "film.h"
#include <QString>

class Educational : public Film
{
private:
    QString m_Subject;
    int m_GradeLevel;
public:
    Educational(similar_to_Entertainment sixparameters);
    Educational(QStringList propList);
    QString toString(bool labeled, QString sepChar);
};

#endif // EDUCATIONAL_H
