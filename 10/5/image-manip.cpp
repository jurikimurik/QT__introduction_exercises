#include <QRect>
#include <QColor>
#include "image-manip.h"
#include <QDebug>

//start id=mirrorpixels
void MirrorPixels::reflect() {
    qDebug() << "MirrorPixels::reflect()";
    m_Saved = m_Image.copy(QRect());
    int h(m_Image.height()), w(m_Image.width());
    QRgb pix;
    if(m_Horizontal) {
        int midpt = h / 2;
        for(int x = 0; x < w; ++x) {
            for(int y = 0; y < midpt; ++y) {
                pix = m_Image.pixel(x,y);
                m_Image.setPixel(x,h - 1 - y,pix);
            }
        }
    }
    else {
        int midpt = w / 2;
        for(int y = 0; y < h; ++y) {
            for(int x = 0; x < midpt; ++x) {
                pix = m_Image.pixel(x,y);
                m_Image.setPixel(w-1-x,y,pix);
            }
        }
    }
}

void MirrorPixels::redo() {
    qDebug() << "MirrorPixels::redo()";
    reflect();
}


void MirrorPixels::undo() {
    qDebug() << "MirrorPixels::undo()";
    m_Image = m_Saved.copy(QRect());
}
//end

/////////////////////////////////////////////////////////////////////////////////

void ProcessColors::processing()
{
    int h(m_Image.height()), w(m_Image.width());
    m_Saved = m_Image.copy(QRect()); // zachowaj kopię całego obrazu
    for(int y = 0; y < h; ++y) {
        for(int x = 0; x < w; ++x) {
            m_Image.setPixel(x,y,pixelProcessing(x, y));
        }
    }
}

void ProcessColors::undo()
{
    qDebug() << "ProcessColors::undo()";
    m_Image = m_Saved.copy(QRect());
}

void ProcessColors::redo()
{
    qDebug() << "ProcessColors::redo()";
    processing();
}

/////////////////////////////////////////////////////////////////////////////////

QRgb AdjustColors::pixelProcessing(int x, int y)
{
    QRgb oldpix = m_Image.pixel(x,y);
    int r = qRed(oldpix) * m_RedAdj;
    int g = qGreen(oldpix) * m_GreenAdj;
    int b = qBlue(oldpix) * m_BlueAdj;
    return qRgb(r,g,b);
}

/////////////////////////////////////////////////////////////////////////////////

QRgb GrayColors::pixelProcessing(int x, int y)
{
    QRgb oldpix = m_Image.pixel(x,y);
    int r = qRed(oldpix) * 0.30;
    int g = qGreen(oldpix) * 0.59;
    int b = qBlue(oldpix) * 0.11;
    int lumination = (r + g + b) / 3 * 3;
    return qRgb(lumination,lumination,lumination);
}

/////////////////////////////////////////////////////////////////////////////////


QRgb NegateColors::pixelProcessing(int x, int y)
{
    QRgb oldpix = m_Image.pixel(x,y);
    int r = 255 - qRed(oldpix);
    int g = 255 - qGreen(oldpix);
    int b = 255 - qBlue(oldpix);
    return qRgb(r,g,b);
}

/////////////////////////////////////////////////////////////////////////////////

QRgb SwapColors::pixelProcessing(int x, int y)
{
    QRgb oldpix = m_Image.pixel(x,y);
    int r = qBlue(oldpix);
    int g = qRed(oldpix);
    int b = qGreen(oldpix);
    return qRgb(r,g,b);
}

/////////////////////////////////////////////////////////////////////////////////

QRgb ThreeColors::pixelProcessing(int x, int y)
{
    QRgb oldpix = m_Image.pixel(x,y);
    int r = qBlue(oldpix);
    int g = qRed(oldpix);
    int b = qGreen(oldpix);
    int ci = (r+g+b) / 3;
    if(ci < 85) {
        r = 0;
        b = 0;
    } else if(ci >= 85 && ci < 170) {
        b = 0;
        g = 0;
    } else {
        r = 0;
        g = 0;
    }
    return qRgb(r,g,b);
}

/////////////////////////////////////////////////////////////////////////////////

