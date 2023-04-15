#ifndef FENDER_H
#define FENDER_H

#include "BodyPart.h"
#include <QString>

class Fender : public BodyPart {
private:
    QString m_Nazwa;
public:
    Fender(QString nazwa, int id, int cena, int size, QString dokladna_nazwa);
    QString toString();
    int getCena();
};

#endif // FENDER_H
