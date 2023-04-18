#include <QtWidgets>
#include "palindate.h"
#include "palindromeform.h"

//start
PalindromeForm::PalindromeForm(QWidget* parent) : QWidget(parent),
  m_Palindate(new Palindate),
  m_LineEdit(new QLineEdit),
  m_Result(new QLabel) {
    setupForm();
}

void PalindromeForm::setupForm() {
   setWindowTitle("Tester palindromów");
   m_LineEdit->setValidator(m_Palindate);
   connect(m_LineEdit, SIGNAL(returnPressed()),
           this, SLOT(showResult())); 
//end
   connect(m_LineEdit, SIGNAL(textChanged(QString)),
           this, SLOT(showResult()));
   QPushButton* againButton = new QPushButton("Inny palindrom", this);
   QPushButton* quitButton = new QPushButton("Wyjście", this);
   QFormLayout *formL = new QFormLayout(this);
   formL->addRow("Słowo do przetestowania:", m_LineEdit);
   formL->addRow("Wynik:", m_Result);
   QHBoxLayout *hBox = new QHBoxLayout;
   formL->addRow(hBox);
   hBox->addWidget(againButton);
   hBox->addWidget(quitButton);
   m_Result->setFrameStyle(QFrame::Panel);
   m_Result->setFrameShadow(QFrame::Raised);
   connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
   connect(againButton, SIGNAL(clicked()), this, SLOT(again()));
   move(500, 500); /* Ustaw okno na środku ekranu (mniej więcej). */
//start
}
void PalindromeForm::showResult() {
   QString str = m_LineEdit->text();
   int pos(0);
   if(m_Palindate->validate(str,pos) == QValidator::Acceptable) {
      m_InputString = str;
      m_Result->setText("Poprawny palindrom!");
   }
   else {
      m_InputString = "";
      m_Result->setText("To nie palindrom!");
   }
}
//end
void PalindromeForm::again() {
   m_LineEdit->clear();
   m_Result->setText("");
   m_LineEdit->setFocus();
}

