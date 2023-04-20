#include "puzzleview.h"

#include <QDebug>

PuzzleView::PuzzleView(PuzzleModel* model) : m_Model(model)
{
    m_Layout = new QGridLayout(this);
    for(int y = 1; y <= model->getRows(); ++y)
    {
        for(int x = 1; x <= model->getCols(); ++x)
        {
            auto ptr = new Tile(m_Model->value(y, x));

            if(m_Model->value(y, x) != model->getSize())
                ptr->setText(ptr->objectName());
            else
                ptr->setEnabled(false);

            m_Buttons.addButton(ptr);
            m_Layout->addWidget(ptr, y, x);
        }
    }
    setLayout(m_Layout);

    connect(&m_Buttons, &QButtonGroup::buttonPressed, this, &PuzzleView::tryToSlide);
}

void PuzzleView::refresh()
{

}

void PuzzleView::tryToSlide(QAbstractButton *button)
{
    qDebug() << button->objectName() << Qt::endl << Qt::flush;
    if(m_Model->slide(button->objectName().toInt()))
    {
        refresh();
    }
}
