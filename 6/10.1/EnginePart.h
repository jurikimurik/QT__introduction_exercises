#ifndef ENGINEPART_H
#define ENGINEPART_H

#include "AutoPart.h"
#include <QString>

enum class Important {
    Very,
    More_or_less,
    not_really
};

class EnginePart : public AutoPart {
private:
    Important jak_wazny;
public:
    EnginePart(QString nazwa, int id, int cena, Important waznosc);
    virtual QString toString() = 0;
    virtual int getCena();

};

#endif // ENGINEPART_H
