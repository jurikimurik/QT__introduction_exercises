#ifndef USER_H
#define USER_H

#include <dataobject.h>

/** Zawiera dodatkowe informacje o stanie użytkownika. */
class User : public DataObject {
    Q_OBJECT
    Q_PROPERTY( QString Name READ getName WRITE setName );
 public:
    User(QObject* parent=0);

 public slots:
    void setName(const QString& name);
    QString getName() const;
 private:
    QString m_Name;
    // TODO: dodaj ulubiony kolor
};

#endif

