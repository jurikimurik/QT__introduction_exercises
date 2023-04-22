#include "keysequencelabel.h"

#include "ui_ksl.h"

KeySequenceLabel::KeySequenceLabel(QWidget* parent) : Ui_KSL(parent),
    m_browserAction(new QObjectBrowserAction(this))
{
    startTimer(2000);
    m_paints = 0;
}

void KeySequenceLabel::timerEvent(QTimerEvent *e) {
    this->ui->lcdNumber->display(m_painsts);
}
