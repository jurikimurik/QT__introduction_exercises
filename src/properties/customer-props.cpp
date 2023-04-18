#include "customer-props.h"
#include <QVariant>
#include <QMetaObject>
#include <QMetaEnum>
//start
Customer::Customer(const QString name, QObject* parent)
:QObject(parent) {
    setObjectName(name);
}

void Customer::setId(const QString &newId) {
    if (newId != m_id) {  
        QString oldId = m_id;
        m_id = newId;     
        emit valueChanged("id", newId, oldId);
    }
}
//end

void Customer::setName(const QString &newName) {
    if (newName != m_name) {
        QString oldName = m_name;
        m_name=newName;
        emit valueChanged("name", newName, oldName);
    }
}


void Customer::setAddress(const QString &newAddress) {
    if (m_address != newAddress) {
        QString oldAddress = m_address;
        m_address=newAddress;
        addressChanged(newAddress);
    }   
}

void Customer::setPhone(const QString &newPhone) {
    if (newPhone != m_phone) {
        QString oldPhone = m_phone;      
        m_phone=newPhone;
        emit phoneChanged(newPhone);
    }   
}


void Customer::setDateEstablished(const QDate & newDate) {
    m_date = newDate;
}

//start
void Customer::setType(CustomerType theType) {
    if (m_type != theType) {
        CustomerType oldType = m_type;
        m_type = theType;
        emit valueChanged("type", theType, oldType);
    }
}

/* Metoda do tworzenia wartości enum na podstawie QString */
void Customer::setType(QString newType) {           /* Przeładowana wersja przyjmująca jako argument łańcuch znaków QString. */

    static const QMetaObject* meta = metaObject();  /* Statyczne zmienne lokalne: inicjalizacja ma miejsce tylko raz. */
    static int propindex = meta->indexOfProperty("type");
    static const QMetaProperty mp = meta->property(propindex);

    QMetaEnum menum = mp.enumerator();              /* Ten kod będzie uruchamiany za każdym razem. */
    const char* ntyp = newType.toLatin1().data();
    CustomerType theType =
                   static_cast<CustomerType>(menum.keyToValue(ntyp));
    
    if (theType != m_type) {                        /* Zawsze sprawdzaj, czy potrzebny jest sygnał valueChanged. */
        CustomerType oldType = m_type;
        m_type = theType;
        emit valueChanged("type", theType, oldType);
    }
}

QString Customer::getTypeString() const {
    return property("type").toString();
}
//end






