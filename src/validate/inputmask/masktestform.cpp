#include <QtWidgets>
#include "masktestform.h"
//start
MaskTestForm::MaskTestForm(): m_InputMask(new QLineEdit), 
    m_StringEntry(new QLineEdit), m_Result(new QLabel) {
    setupForm();
    move(500, 500); /* Ustaw okno na środku ekranu (mniej więcej). */
}
 
void MaskTestForm::setupForm() {
    setWindowTitle("Maski Demo");
    QPushButton* againButton = new QPushButton("Inna maska", this);
    QPushButton* quitButton = new QPushButton("Koniec", this);
    QFormLayout *form = new QFormLayout(this);
    form->addRow("Maska:", m_InputMask);
    form->addRow("Dane wejściowe: ", m_StringEntry);
    form->addRow("Wynik:", m_Result);
    connect(m_InputMask, SIGNAL(returnPressed()),
            this, SLOT(installMask()));
    connect(m_StringEntry, SIGNAL(returnPressed()),
            this, SLOT(showResult())); 

//end
    QHBoxLayout *hBox = new QHBoxLayout;
    form->addRow(hBox);
    hBox->addWidget(againButton);
    hBox->addWidget(quitButton);

    m_Result->setFrameStyle(QFrame::Panel);
    m_Result->setFrameShadow(QFrame::Raised);

    connect(m_InputMask, SIGNAL(textChanged(QString)),
            this, SLOT(installMask()));
    connect(m_StringEntry, SIGNAL(textChanged(QString)),
            this, SLOT(showResult()));
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(againButton, SIGNAL(clicked()), this, SLOT(again()));
//start
}
void MaskTestForm::installMask() {
    m_StringEntry->setInputMask(m_InputMask->text());
}
//end
void MaskTestForm::showResult() {
    QString str = m_StringEntry->text();
    m_Result->setText(str);
}

void MaskTestForm::again() {
    m_StringEntry->clear();
    m_Result->setText("");
    m_StringEntry->setFocus();
}
//end
