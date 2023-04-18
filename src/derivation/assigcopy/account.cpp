#include  "account.h"

//start id=ctor
Account::Account(unsigned acctNum, double balance, QString owner) :
     m_AcctNum(acctNum), m_Balance(balance), m_Owner(owner)
    { }

JointAccount::JointAccount (unsigned acctNum, double balance,
                            QString owner, QString jowner)
    :Account(acctNum, balance, owner),
     m_JointOwner(jowner)   /* Wymagana inicjalizacja klasy bazowej. */
     { }

JointAccount::JointAccount (const Account& acc, QString jowner)
    :Account(acc),          /* Wywołanie konstruktora kopiującego wygenerowanego przez kompilator. */
     m_JointOwner(jowner)
    { }
//end


