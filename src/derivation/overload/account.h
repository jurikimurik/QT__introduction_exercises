#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QDate>
#include <QString>
//start
class Account {
public:
    Account(unsigned acctno, double bal, QString owner);
    virtual ~Account() { }
    virtual void deposit(double amt);
    virtual QString toString() const;
    virtual QString toString(char delimiter);   /* Funkcja przeładowana. */
protected:
    unsigned  m_AcctNo;
    double    m_Balance;
    QString   m_Owner;
};

class InsecureAccount: public Account {
public:
    InsecureAccount(unsigned acctno, double bal, QString owner);
    QString toString() const;                   /* Przesłania metodę bazową i ukrywa toString(char). */
    void deposit(double amt, QDate postDate);   /* Nie przesłania metody, ale ukrywa wszystkie metody
				Account::deposit(). */
};
//end
#endif        //  #ifndef ACCOUNT_H


