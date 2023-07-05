#include "lifeworker.h"
#include "lifeserver.h"
enum {DEAD=0, ALIVE=1};

/** Liczenie sąsiadów */
static int neighborCount(const QImage &img, int x, int y) {
    int retval = 0;
    int wid = img.width();
    int height = img.height();
    for (int c = x-1; c < x+2; c++) {
        int wc = c;                             /* opakowana kolumna */
        if (wc >= wid) wc = 0;
        else if (wc < 0) wc = wid - 1;
        for (int r = y-1; r < y+2; ++r) {
            if ((c == x) && (r == y)) continue; /* nie licz mnie  */
            int wr = r;                         /* opakowany wiersz */
            if (wr < 0) wr = height - 1;
            else if (wr >= height) wr = 0;
            if (ALIVE == img.pixelIndex(wc, wr))
                retval ++;
        }
    }
    return retval;
}

LifeWorker::LifeWorker(LifeServer *parent, QRect rect, const QImage &image) :
    QThread(parent), m_server(parent), m_rect{rect}, m_image{image}
{

}

void LifeWorker::run()
{
    do {
        QRect rect = m_rect;
        QImage image = m_image;
        QImage next = QImage(rect.size(), QImage::Format_Mono);
        next.fill(DEAD);
        int h = rect.height();  int w = rect.width();
        for (int c=0; c<w; ++c) {
            for (int r=0; r<h; ++r) {
                int x = c+rect.x();
                int y = r+rect.y();
                bool isAlive = (image.pixelIndex(x, y) == ALIVE);
                int nc = neighborCount(image, x, y);
                if (!isAlive && nc == 3)
                    next.setPixel(c, r, ALIVE);
                if (!isAlive) continue;
                if (nc == 2 || nc == 3)
                    next.setPixel(c,r, ALIVE);
            }
        }
        image = next;
        m_server->updatePartOfImage(rect, image);
    }   while(m_server->isRunning());
}
