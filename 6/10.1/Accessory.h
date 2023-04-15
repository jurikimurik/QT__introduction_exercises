#ifndef ACCESSORY_H
#define ACCESSORY_H

enum class AccessoryType {
    in,
    outside,
    electonics,
    skin
};

class Accessory : public AutoPart {
private:
    AccessoryType m_Typ;
public:
    BodyPart(QString nazwa, int id,  int cena, int size, AccessoryType typ);
    virtual QString toString();
    virtual int getCena();

};

#endif // ACCESSORY_H
