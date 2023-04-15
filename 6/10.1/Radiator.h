#ifndef RADIATOR_H
#define RADIATOR_H

#include "BodyPart.h"
#include <QString>

class Radiator : public BodyPart {
private:
    QString m_Nazwa;
public:
    Fender(QString nazwa, int id, int cena, int size, QString dokladna_nazwa);
    QString toString();
    int getCena();
};

#endif // RADIATOR_H
