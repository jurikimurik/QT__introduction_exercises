#ifndef PRIMESERVER_H
#define PRIMESERVER_H

#include <QDebug>
#include <QFutureWatcher>
#include <QMutex>
#include <QString>
#include <QElapsedTimer>
#include <QtConcurrent>



class PrimeServer : public QObject
{
    Q_OBJECT
public:
    explicit PrimeServer(QObject *parent = nullptr);
    void doCalc(int numThreads, int highestPrime, bool concurrent = false);
    int nextNumberToCheck();
    void foundPrime(int);
    bool isRunning() const;
    int lastNumber() const;

    QFutureWatcher<void> *watcher();

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
    QElapsedTimer m_timer;
    QMutex m_nextMutex;
    QMutex m_listMutex;
    QSet<QObject*> m_threads;
private slots:
    void handleWatcherFinished();
    void doConcurrent();
private:
    bool m_concurrent;
    int m_generateTime;
    QFutureWatcher<void> m_watcher;
};

#endif // PRIMESERVER_H
