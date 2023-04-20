#include "puzzlemodel.h"
#include <random>
#include <chrono>
#include <algorithm>

#include <QDebug>
void wypisz(QString co, bool czy_koniec = true)
{
    qDebug() << co;
    if(czy_koniec)
        qDebug() << Qt::endl;
    qDebug() << Qt::flush;
}


PuzzleModel::PuzzleModel(QObject* parent, int rows, int cols) : QObject(parent), m_Rows(rows), m_Cols(cols)
{
    for(int i = 0; i < m_Rows*m_Cols; ++i)
    {
        m_Positions.push_back(i+1);
    }

    std::default_random_engine dre(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(m_Positions.begin(), m_Positions.end(), dre);
}



int PuzzleModel::value(int r, int c)
{
    int index = (r-1)*m_Cols + (c-1);
    if(index >= 0 && index < m_Positions.size())
    {
        return m_Positions.at(index);
    } else {
        return -1;
    }
}

bool PuzzleModel::neighboring(int r, int c)
{
    if(value(r, c) == m_Positions.size())
    {
        return false;
    } else {
        return true;
    }
}

bool PuzzleModel::slide(int tilenum)
{
    int position = m_Positions.indexOf(tilenum);
    int r = (position / m_Cols) + 1;
    int c = position - (r-1)*m_Cols + 1;

    int with_r = r;
    int with_c = c;

    if(!neighboring(r+1, c)) {
        with_r = r+1;
    } else if (!neighboring(r-1, c)) {
        with_r = r-1;
    } else if (!neighboring(r, c+1)) {
        with_c = c+1;
    } else if (!neighboring(r, c-1)) {
        with_c = c-1;
    }

    if((r == with_r && c == with_c) || (with_r == 0 || with_c == 0)) {
        return false;
    }

    int position_to = m_Positions.indexOf(value(with_r, with_c));
    m_Positions.swapItemsAt(position, position_to);
    return true;
}

QString PuzzleModel::getPlaneInText()
{
    QString str;
    for(int y = 1; y <= m_Rows; ++y)
    {
        for(int x = 1; x <= m_Cols; ++x)
        {
            str += QString::number(value(y, x)) + " ";
        }
        str += "\n";
    }

    return str;
}


