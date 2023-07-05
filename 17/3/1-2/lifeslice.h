#ifndef LIFESLICE_H
#define LIFESLICE_H

#include <QRect>
#include <QImage>


/** Małe zadanie do wykonania - "plasterek życia" w grze w życie według Conwaya.
*/
//start
struct LifeSlice {
    LifeSlice() {};
    LifeSlice(QRect r, QImage i) : rect(r), image(i) {}

    /** Prostokąt, do którego należy ten plasterek */
    QRect rect;
    /** dane grafiki */
    QImage image;
};
//end

#endif // LIFESLICE_H
