#ifndef LIFESERVER_H
#define LIFESERVER_H

#include <QMutex>
#include <QObject>
#include <QSet>
#include <QThread>
#include <QRect>
#include <QImage>

class LifeServer : public QObject
{
    Q_OBJECT
public:
    explicit LifeServer(QObject *parent, const QImage&);
    void beginSimulation(int numThreads);
    void updatePartOfImage(QRect, QImage);
    bool isRunning() const;
public slots:
    void startStop(bool);
private:
    int m_numThreads;
    bool m_isRunning;
    const QImage& m_image;
    QMutex m_imageMutex;
    QSet<QThread*> m_threads;
};

#endif // LIFESERVER_H
