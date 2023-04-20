#include "puzzleview.h"

PuzzleView::PuzzleView(PuzzleModel* model) : m_Model(model)
{
    m_Layout = new QGridLayout(this);
    for(int i = 0; i < model->getSize(); ++i)
    {
        auto ptr = new Tile(m_Model->value(i));
        ptr->setText(ptr->objectName());

        m_Buttons.addButton(ptr);
        m_Layout->addWidget(ptr);
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
