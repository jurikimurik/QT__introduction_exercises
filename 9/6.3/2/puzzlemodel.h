#ifndef PUZZLEMODEL_H
#define PUZZLEMODEL_H

#include <QObject>
#include <QList>
#include <signal.h>

#include <QString>

class PuzzleModel : public QObject
{
    Q_OBJECT
private:
    QList<int> m_Positions;
    int m_Rows;
    int m_Cols;
public:
    PuzzleModel(int rows, int cols);

    int value(int r, int c);
    int value(int pos);
    bool slide(int tilenum);
    bool neighboring(int r, int c);
    //gridChanged() signal;

    int getSize() const {
        return m_Rows*m_Cols;
    }

    //DEBUG
    QString getPlaneInText();
};

#endif // PUZZLEMODEL_H
