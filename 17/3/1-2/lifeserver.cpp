#include "lifeserver.h"
#include <QApplication>
#include <QPainter>

LifeServer::LifeServer(QObject *parent, QImage &image, const QSize &size)
    : QObject{parent}, m_image(image), m_size(size)
{

}

void LifeServer::beginSimulation(int numThreads)
{
    m_numThreads = numThreads;
    m_threads.clear();

    int segments = numThreads;
    int ws = m_size.width()/segments;
    for(int i = 0; i < segments; ++i) {
        int tlx = i*ws;
        QRect rect(tlx, 0, ws, m_size.height());

        LifeWorker *thread = new LifeWorker(this, rect, m_image);
        m_threads << thread;
    }
    startStop(true);
}

bool LifeServer::isRunning() const
{
    return m_isRunning;
}

void LifeServer::startStop(bool onOff)
{
    if(onOff) {
        m_isRunning = true;
        for(QThread* thread : m_threads)
        {
            thread->start();
        }
    } else {
        m_isRunning = false;
        for(QThread* thread : m_threads)
        {
            thread->terminate();
        }
    }
}

void LifeServer::updatePartOfImage(QRect rect, QImage image)
{
    qApp->processEvents();
    QMutexLocker locker(&m_imageMutex);
    if(image.isNull())
        image = QImage(m_size, QImage::Format_Mono);
    QPainter painter(&m_image);
    painter.drawImage(rect.topLeft(), image);
}
