#ifndef IMAGE_MANIP_H
#define IMAGE_MANIP_H

#include <QUndoCommand>
#include <QImage>

//start
class AdjustColors : public QUndoCommand {
public:
   AdjustColors(QImage& img, double radj, double gadj, double badj)
     : m_Image(img), m_Saved(img.size(), img.format()), m_RedAdj(radj), 
     m_GreenAdj(gadj), m_BlueAdj(badj)   {setText("adjust colors"); }
   virtual void undo();
   virtual void redo();
private:
    QImage& m_Image;
    QImage m_Saved;
    double m_RedAdj, m_GreenAdj, m_BlueAdj;
    void adjust(double radj, double gadj, double badj);

};

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

class GrayColors : public QUndoCommand {
public:
   GrayColors(QImage& img) : m_Image(img), m_Saved(img.size(), img.format())
    {setText("wyszaruj obrazek");}
   virtual void undo();
   virtual void redo();
private:
   QImage& m_Image;
   QImage m_Saved;
   void wyszaruj();
};

class NegateColors : public QUndoCommand {
   public:
   NegateColors(QImage& img) : m_Image(img), m_Saved(img.size(), img.format())
   {setText("negatyw obrazku");}
   virtual void undo();
   virtual void redo();
   private:
   QImage& m_Image;
   QImage m_Saved;
   void negatyw();
};

class SwapColors : public QUndoCommand {
   public:
   SwapColors(QImage& img) : m_Image(img), m_Saved(img.size(), img.format())
   {setText("Zamiana kolorow obrazka");}
   virtual void undo();
   virtual void redo();
   private:
   QImage& m_Image;
   QImage m_Saved;
   void zamiana();
};

class ThreeColors : public QUndoCommand {
   public:
   ThreeColors(QImage& img) : m_Image(img), m_Saved(img.size(), img.format())
   {setText("Trzy kolory obrazka");}
   virtual void undo();
   virtual void redo();
   private:
   QImage& m_Image;
   QImage m_Saved;
   void trzy_kolory();
};

#endif        //  #ifndef IMAGE-MANIP_H
