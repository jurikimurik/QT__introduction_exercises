#ifndef ISBNVALIDATOR_H
#define ISBNVALIDATOR_H

#include <QValidator>
#include <QString>
#include <QChar>

class ISBNValidator : public QValidator
{
    Q_OBJECT
public:
    ISBNValidator(QObject *parent = nullptr);

    // QValidator interface
public:
    State validate(QString &str, int &from) const;
};

#endif // ISBNVALIDATOR_H
