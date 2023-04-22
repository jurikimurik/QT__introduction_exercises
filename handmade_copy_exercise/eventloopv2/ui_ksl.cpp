#include "ui_ksl.h"
#include "ui_ui_ksl.h"

Ui_KSL::Ui_KSL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ui_KSL)
{
    ui->setupUi(this);
}

Ui_KSL::~Ui_KSL()
{
    delete ui;
}
