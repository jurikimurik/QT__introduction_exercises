#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include <QDebug>


//start id=account
class Account {
 public:
    Account(unsigned acctNum, double balance, QString owner);
    virtual ~Account(){
      qDebug() << "Zamykamy konto - wysyłamy e-mail " 
               << "do właściciela:" << m_Owner; }
    virtual QString getName() const {return m_Owner;}
    // inne funkcje wirtualne
 private:
    unsigned  m_AcctNum;
    double    m_Balance;
    QString    m_Owner;
};
//end
//start id=jointaccount
class JointAccount : public Account {
 public:
  JointAccount (unsigned acctNum, double balance, 
                QString owner, QString jowner);
  JointAccount(const Account & acct, QString jowner);
  ~JointAccount() {
      qDebug() << "Zamykamy konto - wysyłamy e-mail " 
              << "do współwłaściela:" << m_JointOwner; }
  QString getName() const { 
    return QString("%1 i %2").arg(Account::getName())
                   .arg(m_JointOwner);
  }
  // inne przesłonięcia
 private:
  QString m_JointOwner;
};
//end
#endif        //  #ifndef ACCOUNT_H

