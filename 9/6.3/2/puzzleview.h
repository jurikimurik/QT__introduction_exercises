#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include <QObject>
#include "puzzlemodel.h"
#include "tile.h"
#include <QButtonGroup>
#include <QGridLayout>

class PuzzleView : public QWidget
{
    Q_OBJECT
private:
    PuzzleModel* m_Model;
    QGridLayout* m_Layout;
    QButtonGroup m_Buttons;
public:
    PuzzleView(PuzzleModel* model);
    void refresh();
    void tryToSlide(QAbstractButton *button);
    void wygrana();
    void shuffle();
    void exit();
};

#endif // PUZZLEVIEW_H
