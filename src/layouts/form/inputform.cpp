#include "inputform.h"
#include <QFormLayout>
#include <QDateEdit>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMessageBox>
#include <QColorDialog>
#include <QSettings>
#include <QVariant>
#include <QPalette>

InputForm::InputForm(QWidget* parent)
: QDialog(parent) {

    QSettings s;
    setWindowTitle("QFormlayout demo");
    QVariant v = s.value("color/favorite", QVariant());
    if (!v.isNull()) m_color = v.value<QColor>();

//start id="form"
    m_name = new QLineEdit;
    m_birthday = new QDateEdit;
    m_birthday->setDisplayFormat("dd/MM/yyyy");
    m_colorButton = new QPushButton(tr("Wybierz"));
    m_colorButton->setAutoFillBackground(true);

    m_buttons = new QDialogButtonBox(QDialogButtonBox::Ok |
                                     QDialogButtonBox::Cancel);

    QVBoxLayout* vbox = new QVBoxLayout;
    QFormLayout* layout = new QFormLayout;

    layout->addRow(tr("Imię"), m_name);                               /* Stwórz i dodaj etykietę QLabel oraz widżet do wprowadzania danych — wszystko w jednej linii! */
    layout->addRow(tr("Data urodzenia"), m_birthday);
    layout->addRow(tr("Ulubiony kolor"), m_colorButton);


    vbox->addLayout(layout);                /* W ten sposób możemy osadzić jeden układ w drugim. */
    vbox->addWidget(m_buttons);

    Q_ASSERT(vbox->parent() == 0);
    Q_ASSERT(m_birthday->parent() == 0);
    setLayout(vbox);                        /* Zmienia rodzica już wcześniej rozmieszczonych widżetów. */
    Q_ASSERT(vbox->parent() == this);
    Q_ASSERT(m_birthday->parent() == this);
    //end

    connect (m_colorButton, SIGNAL(clicked()),
             this, SLOT(chooseColor()));
    connect (m_buttons, SIGNAL(accepted()),
             this, SLOT(accept()));
    connect(m_buttons, SIGNAL(rejected()),
            this, SLOT(reject()));
    updateUi();
}

void InputForm::accept() {
    QSettings s;
    s.setValue("color/favorite", m_color);

    QDate birthday = m_birthday->date();
    int days = birthday.daysTo(QDate::currentDate());
    QMessageBox::information(this, tr("Zgadula wieku"),
        tr("Masz %1 lat	.").arg(days / 365));
    QDialog::accept();
}

void InputForm::chooseColor() {

    m_color = QColorDialog::getColor(m_color, this);
    updateUi();
}

void InputForm::updateUi() {
    QPalette p = m_colorButton->palette();
    p.setColor(QPalette::Button, m_color);
    m_colorButton->setPalette(p);


}
