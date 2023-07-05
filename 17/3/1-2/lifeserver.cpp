#include "lifeserver.h"

LifeServer::LifeServer(QObject *parent, const QImage &image)
    : QObject{parent}, m_image(image)
{

}

void LifeServer::beginSimulation(int numThreads)
{

}

bool LifeServer::isRunning() const
{
    return m_isRunning;
}

void LifeServer::startStop(bool)
{

}

void LifeServer::updatePartOfImage(QRect rect, QImage image)
{

}
