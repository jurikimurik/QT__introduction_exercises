#ifndef PRIMETHREAD_H
#define PRIMETHREAD_H

#include <QThread>
#include "primeserver.h"
#include "isprime.h"



class PrimeThread : public QThread
{
    Q_OBJECT
public:
    explicit PrimeThread(PrimeServer *parent);
    void run();
private:
    PrimeServer *m_server;

};

#endif // PRIMETHREAD_H
