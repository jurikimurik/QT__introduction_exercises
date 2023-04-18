#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QVariant>
//start
class Customer : public QObject {
    Q_OBJECT                                                        /* Makro wymagane przez moc do wstępnego przetworzenia klasy. */

    /* Każda deklaracja właściwości ma następującą składnię:

    Q_PROPERTY( typ nazwa READ funkcjaDostepuGet [WRITE funkcjaDostepuSet]
    [RESET funkcjaZerujaca] [NOTIFY sygnalPowiadomienia] [DESIGNABLE bool]
    [SCRIPTABLE bool] [STORED bool] )
    */


    Q_PROPERTY( QString id READ getId WRITE setId NOTIFY valueChanged);
    Q_PROPERTY( QString name READ getName WRITE setName 
                NOTIFY valueChanged);
    Q_PROPERTY( QString address READ getAddress WRITE setAddress 
                NOTIFY addressChanged);
    Q_PROPERTY( QString phone READ getPhone WRITE setPhone 
                NOTIFY phoneChanged);
    Q_PROPERTY( QDate dateEstablished READ getDateEstablished );    /* Właściwość tylko do odczytu. */
    Q_PROPERTY( CustomerType type READ getType WRITE setType 
                NOTIFY valueChanged);

  public:
    enum CustomerType
    { Corporate, Individual, Educational, Government };             /* Definicja typu enum musi znaleźć się w tej samej definicji klasy co makro Q_ENUMS. */
    Q_ENUMS( CustomerType ) ;                                       /* Specjalne makro do generowania funkcji konwertujących pomiędzy łańcuchami znaków a wartościami enum. Musi być w tej samej klasie. */

    explicit Customer(const QString name = QString(),               /* Zadeklarowana jako explicit, ponieważ nie chcemy przypadkowych konwersji z QString do Customer. */ 
        QObject* parent = 0);                                       
                                                                  
    QString getId() const {
        return m_id;
    }
//end
    QString getName() const {
        return m_name;
    }
    QString getAddress() const {
        return m_address;
    }
    QString getPhone() const {
        return m_phone;
    }
    QDate getDateEstablished() const {
        return m_date;
    }
    CustomerType getType() const {
        return m_type;
    }
    QString getTypeString() const;
    void setId(const QString& newId);

    void setName(const QString& newName);
    void setAddress(const QString& newAddress);
    void setPhone(const QString& newPhone);
    void setDateEstablished(const QDate&  newDate);
//start
    // Przeładowane, dzięki czemu możemy ustawić typ na dwa różne sposoby
    void setType(CustomerType newType);
    void setType(QString newType);
signals:
    void addressChanged(QString newAddress);
    void phoneChanged(QString newPhone);
    void typeChanged(CustomerType type);
    void valueChanged(QString propertyName,
        QVariant newValue, QVariant oldValue = QVariant());
private:
    QString m_id, m_name, m_address, m_phone;
    QDate m_date;
    CustomerType m_type;
};
//end
#endif
