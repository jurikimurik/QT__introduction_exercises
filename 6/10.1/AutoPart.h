#ifndef AUTOPART_H
#define AUTOPART_H

#include <QString>

class AutoPart {
private:
    QString m_Nazwa;
    int m_Cena;
    const int cm_Id;
public:
    AutoPart(QString nazwa, int id, int cena);

    int getId();
    PartType getPartType();
    virtual QString toString() = 0;
    virtual int getCena();
};

#endif // AUTOPART_H
