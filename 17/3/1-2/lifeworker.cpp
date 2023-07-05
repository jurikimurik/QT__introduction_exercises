#include "lifeworker.h"
#include "lifeserver.h"

LifeWorker::LifeWorker(LifeServer *parent, QRect rect, const QImage &image) :
    QThread(parent), m_rect{rect}, m_image{image}
{

}

void LifeWorker::run()
{

}
