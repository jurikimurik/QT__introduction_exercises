#include "puzzleview.h"

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
}

void PuzzleView::refresh()
{

}

void PuzzleView::tryToSlide(Tile *button)
{
    if(m_Model->slide(button->m_Number))
    {
        refresh();
    }
}
