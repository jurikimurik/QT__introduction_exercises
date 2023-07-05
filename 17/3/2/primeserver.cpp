#include "primeserver.h"
#include "primethread.h"
#include <QFutureWatcher>

PrimeServer::PrimeServer(QObject *parent)
    : QObject{parent}, m_concurrent{false} {
    m_isRunning = false;
}

void PrimeServer::doCalc(int numThreads, int highestPrime, bool concurrent)
{
    m_isRunning = true;
    m_numThreads = numThreads;
    m_highestPrime = highestPrime;
    m_primes.clear();
    m_primes << 2 << 3;
    m_threads.clear();
    m_nextNumber = 3;
    m_timer.start();
    if(!concurrent) {
        for(int i = 0; i < m_numThreads; ++i) {
            PrimeThread *pt = new PrimeThread(this);
            connect(pt, &PrimeThread::finished, this, &PrimeServer::handleThreadFinished);
            m_threads << pt;
            pt->start();
        }
    }
    else doConcurrent();
}

int PrimeServer::nextNumberToCheck()
{
    QMutexLocker locker(&m_nextMutex);
    if(m_nextNumber >= m_highestPrime)
        return -1;
    else {
        m_nextNumber += 2;
        return m_nextNumber;
    }
}

void PrimeServer::foundPrime(int pn)
{
    QMutexLocker locker(&m_listMutex);
    m_primes << pn;
}

bool PrimeServer::isRunning() const
{
    return m_isRunning;
}

int PrimeServer::lastNumber() const
{
    return m_nextNumber;
}

void PrimeServer::cancel()
{
    QMutexLocker locker(&m_nextMutex);
    m_nextNumber = m_highestPrime+1;
}

void PrimeServer::handleThreadFinished()
{
    QObject* pt = sender();
    m_threads.remove(pt);
    pt->deleteLater();
    if(!m_threads.isEmpty()) return;
    int numPrimes = m_primes.length();
    QString result = QString("%1 watkow z mureksami %2 liczb pierwszych w %3 milisekund. ")
                         .arg(numPrimes).arg(m_timer.elapsed());
    QString r2 = QString("%1 kp/s").arg(numPrimes / m_timer.elapsed());
    qDebug() << result << r2;
    emit results(result + r2);
    m_isRunning = false;
}



void PrimeServer::handleWatcherFinished()
{
    int numPrimes = m_primes.length();
    int msecs = m_timer.elapsed();
    QString result = QString("%1 pula watkow %2 liczb pierwszych w %4/%3 milisekund")
                         .arg(numPrimes).arg(msecs).arg(msecs-m_generateTime)
                         .arg((100.0 * (msecs-m_generateTime)) / msecs);
    QString r2 = QString(" %1 kp/s").arg(numPrimes / msecs);
    qDebug() << result << r2;
    m_watcher.disconnect(this);
    emit results(result + r2);
    m_isRunning = false;
}

void PrimeServer::doConcurrent()
{
    QThreadPool::globalInstance()->setMaxThreadCount(m_numThreads);
    m_primes.clear();
    m_primes << 2;
    for (m_nextNumber = 3; m_nextNumber <= m_highestPrime; m_nextNumber += 2) {
        m_primes << m_nextNumber;
    }
    m_generateTime = m_timer.elapsed();
    qDebug() << m_generateTime << "Wygenerowano " << m_primes.length() << " liczb";
    connect(&m_watcher, &QFutureWatcher<void>::finished, this, &PrimeServer::handleWatcherFinished);
    m_watcher.setFuture(QtConcurrent::filter(m_primes, isPrime));
}

QFutureWatcher<void>* PrimeServer::watcher()
{
    return &m_watcher;
}
