#ifndef PRIMESERVER_H
#define PRIMESERVER_H

#include <QObject>
#include <QMutex>
#include <QTime>
#include <QSet>
#include <QFuture>
#include <QFutureWatcher>
//start
/** Wielowątkowy przykład wyznaczający liczby pierwsze.
    Tworzy wiele wątków robocznych na wielu rdzeniach, 
	pomiędzy które dzielone są obliczenie. Możemy
	porównać rozwiązanie QtConcurrent z użyciem filter().  
*/
class PrimeServer : public QObject
{
    Q_OBJECT
public:
    explicit PrimeServer(QObject* parent =0);
    /** Rozpocznij obliczanie liczb pierwszych
        @param highestPrime najwyższa liczba do sprawdzenia. 
        @param numThreads liczba wątków, które będą mogły być wykorzystane. 
        @param concurrent jeśli true, użyj QtConcurrent::filter zamiast wątków z muteksami. 
    */
    void doCalc(int numThreads, int highestPrime, bool concurrent = false);
    /** Ta metoda jest bezpieczna dla wątków */
    int nextNumberToCheck();
    /** Ta metoda jest bezpieczna dla wątków */
    void foundPrime(int );   
    bool isRunning() const;
public slots:
    void cancel();
private slots:
    void handleThreadFinished();
signals:
    void results(QString);
private:
    int m_numThreads;
    bool m_isRunning;    
    QList<int> m_primes;
    int m_nextNumber;
    int m_highestPrime;
    QTime m_timer;
    QMutex m_nextMutex;
    QMutex m_listMutex;
    QSet<QObject*> m_threads;
//end
//start id=concurrent 
private slots:
    void handleWatcherFinished();
    void doConcurrent();
private:
    bool m_concurrent;
    int m_generateTime;             /* Czas poświęcony na generowanie danych wejściowych */    
    QFutureWatcher<void> m_watcher;
};
//end
#endif // PRIMESERVER_H
