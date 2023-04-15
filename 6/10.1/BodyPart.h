#ifndef BODYPART_H
#define BODYPART_H

#include "AutoPart.h"
#include <QString>

class BodyPart : public AutoPart {
private:
    int m_Size;
public:
    BodyPart(QString nazwa, int id, int cena, int size);
    virtual QString toString() = 0;
    virtual int getCena();

};

#endif // BODYPART_H
