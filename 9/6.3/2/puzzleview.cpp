#include "puzzleview.h"

#include <QDebug>
#include <QMessageBox>

void PuzzleView::wygrana() {
    auto but = QMessageBox::information(this, "Wygrana", "Wygrales! Brawo! Jeszcze jedna rundka?", QMessageBox::Yes | QMessageBox::No);
    if(but == QMessageBox::No)
        exit(EXIT_SUCCESS);
    else {
        m_Model->shuffle();
        refresh();
    }

}

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
    QList<QAbstractButton*> buttons = m_Buttons.buttons();
    for(int i = 0; i < m_Model->getSize(); ++i)
    {
        auto ptr = buttons.at(i);

        QString toName = QString::number(m_Model->value(i));
        ptr->setObjectName(toName);
        ptr->setText(toName);


        if(ptr->objectName() != QString::number(m_Model->getSize()))
            ptr->setEnabled(true);
        else {
            ptr->setEnabled(false);
            ptr->setText(QString());
        }

    }
}

void PuzzleView::tryToSlide(QAbstractButton *button)
{
    if(m_Model->slide(button->objectName().toInt()))
    {
        refresh();
        if(m_Model->checkWin())
            PuzzleView::wygrana();
    }
}
