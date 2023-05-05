#include "inputform.h"
#include "ui_inputform.h"

InputForm::InputForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputForm)
{
    ui->setupUi(this);
    m_BotI = QInputDialog::getInt(this, "Godziny MIN", "Minimum godzin:");
    m_TopI = QInputDialog::getInt(this, "Godziny MAX", "Maksimum godzin: ");

    m_BotD = QInputDialog::getDouble(this, "Stawka MIN", "Minimalna stawka: ");
    m_TopD = QInputDialog::getDouble(this, "Stawka MAX", "Maksymalna stawka: ");

    ui->workedHoursLabel->setText(ui->workedHoursLabel->text().arg(m_BotI).arg(m_TopI));
    ui->moneyPerHourLabel->setText(ui->moneyPerHourLabel->text().arg(m_BotD).arg(m_TopD));

    QIntValidator* iValid = new QIntValidator(m_BotI, m_TopI, this);
    QDoubleValidator* dValid = new QDoubleValidator(m_BotD, m_TopD, 2, this);
    ui->m_IntEntry->setValidator(iValid);
    ui->m_DoubleEntry->setValidator(dValid);
}

InputForm::~InputForm()
{
    delete ui;
}

void InputForm::calculate()
{
    int godziny =  ui->m_IntEntry->text().toInt();
    double stawka = ui->m_DoubleEntry->text().toDouble();

    ui->m_Result->setText(QString::number(stawka*godziny));
}
