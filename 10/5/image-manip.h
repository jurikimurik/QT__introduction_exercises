#ifndef IMAGE_MANIP_H
#define IMAGE_MANIP_H

#include <QUndoCommand>
#include <QImage>


class MirrorPixels : public QUndoCommand {
public:
    virtual void undo();
    virtual void redo();
    //end
    MirrorPixels(QImage& img, bool horiz): m_Image(img), m_Saved(img.size(),
                  img.format()), m_Horizontal(horiz) {
        setText(QString("odbicie krawędzi względem linii %1").arg(horiz
                                                                      ?"poziomej":"pionowej"));
    }
private:
    QImage& m_Image;
    QImage m_Saved;
    bool m_Horizontal;
    void reflect();
};

//REFACTORING BY ME
class ProcessColors : public QUndoCommand {
public:
    ProcessColors(QImage& img) : m_Image(img), m_Saved(img.size(), img.format())
    {setText("jakies dzialanie na obrazku");}
    virtual void undo();
    virtual void redo();
protected:
    QImage& m_Image;
    QImage m_Saved;
    virtual void processing();
    virtual QRgb pixelProcessing(int x, int y) = 0;
};


class AdjustColors : public ProcessColors {
public:
    AdjustColors(QImage& img, double radj, double gadj, double badj)
        : ProcessColors(img), m_RedAdj(radj), m_GreenAdj(gadj), m_BlueAdj(badj)
    {setText("adjust colors"); }
private:
    double m_RedAdj, m_GreenAdj, m_BlueAdj;
    QRgb pixelProcessing(int x, int y);
};



class GrayColors : public ProcessColors {
public:
   GrayColors(QImage& img) : ProcessColors(img)
    {setText("wyszaruj obrazek");}
private:
    QRgb pixelProcessing(int x, int y);
};

class NegateColors : public ProcessColors {
public:
    NegateColors(QImage& img) : ProcessColors(img)
    {setText("negatyw obrazka");}
private:
    QRgb pixelProcessing(int x, int y);
};

class SwapColors : public ProcessColors {
public:
    SwapColors(QImage& img) : ProcessColors(img)
    {setText("zamiana kolorow obrazka");}
private:
    QRgb pixelProcessing(int x, int y);
};

class ThreeColors : public ProcessColors {
public:
    ThreeColors(QImage& img) : ProcessColors(img)
    {setText("trzy kolory obrazka");}
private:
    QRgb pixelProcessing(int x, int y);
};



#endif        //  #ifndef IMAGE-MANIP_H
