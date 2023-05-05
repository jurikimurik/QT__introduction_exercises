#include "masktestform.h"
#include "ui_masktestform.h"

MaskTestForm::MaskTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaskTestForm)
{
    ui->setupUi(this);
    setupForm();
}

MaskTestForm::~MaskTestForm()
{
    delete ui;
}

void MaskTestForm::showResult()
{
    ui->m_Result->setText(ui->m_StringEntry->text());
}

void MaskTestForm::installMask()
{
    ui->m_StringEntry->setInputMask(ui->m_InputMask->text());
}

void MaskTestForm::again()
{
    ui->m_InputMask->setText(QString("999-99-9999"));
    ui->m_StringEntry->setInputMask(QString("999-99-9999"));
    ui->m_StringEntry->setText(QString("123-45-6789"));
    ui->m_Result->setText(QString("123-45-6789"));
}

void MaskTestForm::setupForm()
{
    this->show();
}

/*
 * ANSWERS:
 * 999-99-9999
 * >A9A 9A9
 * 99999-9999
 * (999)999-9999
 * 9-999-999-9999
 * ##999-999-9999 */
