#ifndef ALTERNATOR_H
#define ALTERNATOR_H

#include "EnginePart.h"
#include <QString>

class Alternator : public EnginePart {
private:
    QString m_Model;
public:
    EnginePart(QString nazwa, int id, int cena, Important waznosc, QString model);
    QString toString();
    int getCena();
};

#endif // ALTERNATOR_H
