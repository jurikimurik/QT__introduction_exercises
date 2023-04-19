#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QString name, QObject* parent = nullptr);
    virtual ~Person();
};

#endif // PERSON_H
