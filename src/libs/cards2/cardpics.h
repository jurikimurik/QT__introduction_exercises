#ifndef CARDPICS_H
#define CARDPICS_H

#include <QMap>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QObject>
#include "cards_export.h"

//start
/** Klasa dostarczająca grafiki QImage z widokami kart.
*/
class CARDS_EXPORT CardPics : public QObject {
  public:
    explicit CardPics(QObject* parent=0);
    ~CardPics() ;
    static CardPics* instance();
    /** @param card łańcuch liczb i małych liter 
        ac=ace of clubs (as trefl). ts=ten of spades (dziesięć pik)
        @return grafika QPixmap odpowiadająca numerowi karty w talii */
    QImage get(QString card) const;
    static const QString values;
    static const QString suits;
  protected:
    static QString fileName(QString card);    
  private:
    QMap<QString, QImage> m_images;
};
//end


#endif        //  #ifndef CARDPICS_H
