#include "isbnwindow.h"
#include "ui_isbnwindow.h"

ISBNWindow::ISBNWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ISBNWindow)
{
    ui->setupUi(this);
    m_ISBNEdit = ui->centralwidget->findChild<QLineEdit*>("m_ISBNEdit");
    m_statusEdit = ui->centralwidget->findChild<QLineEdit*>("m_statusEdit");

    m_ISBNEdit->setValidator(new ISBNValidator(m_ISBNEdit));
}

ISBNWindow::~ISBNWindow()
{
    delete ui;
}

void ISBNWindow::checkISBN()
{
    if(m_ISBNEdit->hasAcceptableInput())
        m_statusEdit->setText("Acceptable.");
    else
        m_statusEdit->setText("NOT Acceptable.");
}
