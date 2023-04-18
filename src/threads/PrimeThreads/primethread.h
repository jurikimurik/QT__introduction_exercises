#ifndef PRIMETHREAD_H
#define PRIMETHREAD_H

#include <QThread>
#include "primeserver.h"

/** Wątek konsumencki dla zadania z liczbami pierwszymi */

class PrimeThread : public QThread
{
    Q_OBJECT
public:
    explicit PrimeThread(PrimeServer *parent);
    void run();                         /* Przesłonięcie wymagane. */
private:
    PrimeServer *m_server;

};

#endif // PRIMETHREAD_H
