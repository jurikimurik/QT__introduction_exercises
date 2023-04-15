#ifndef SEATBELT_H
#define SEATBELT_H

#include "Accessory.h"
#include <QString>

class Fender : public Accessory {
private:
    int m_Length;
public:
    Fender(QString nazwa, int id, int cena, int size, int length);
    QString toString();
    int getCena();
};

#endif // SEATBELT_H
