#ifndef LIFESERVER_H
#define LIFESERVER_H

#include <QMutex>
#include <QObject>
#include <QSet>
#include <QThread>
#include <QRect>
#include <QImage>
#include "lifeworker.h"

class LifeServer : public QObject
{
    Q_OBJECT
public:
    explicit LifeServer(QObject *parent, QImage&, const QSize&);
    void beginSimulation(int numThreads);
    void updatePartOfImage(QRect, QImage);
    bool isRunning() const;
public slots:
    void startStop(bool);
private:
    int m_numThreads;
    bool m_isRunning;
    QImage& m_image;
    const QSize& m_size;
    QMutex m_imageMutex;
    QSet<QThread*> m_threads;
};

#endif // LIFESERVER_H
