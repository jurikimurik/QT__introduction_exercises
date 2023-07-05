#ifndef LIFEWORKER_H
#define LIFEWORKER_H

#include <QRect>
#include <QThread>

class LifeServer;

class LifeWorker : public QThread
{
    Q_OBJECT
public:
    explicit LifeWorker(LifeServer *parent, QRect, const QImage&);
    void run();
private:
    QRect m_rect;
    const QImage& m_image;
};

#endif // LIFEWORKER_H
