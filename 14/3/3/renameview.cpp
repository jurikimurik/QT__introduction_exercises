#include "renameview.h"
#include "ui_renameview.h"

RenameView::RenameView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RenameView)
{
    ui->setupUi(this);
}

RenameView::~RenameView()
{
    delete ui;
}

void RenameView::loadPath()
{
    //Zakladamy, ze ladowanie sie nie powiodlo
    ui->nameChangeWidget->setEnabled(false);
    ui->generateButton->setEnabled(false);

    m_directory.setPath(QFileDialog::getExistingDirectory(this));
    if(m_directory.isEmpty())
    {
        ui->statusEdit->setText("Katalog jest pusty!");
        return;
    } else if(!m_directory.isReadable()) {
        ui->statusEdit->setText("Nie da sie odczytac katalogu!");
        return;
    }

    ui->statusEdit->setText("Pomyslnie zaladowano.");
    ui->nameChangeWidget->setEnabled(true);
    ui->generateButton->setEnabled(true);
}

void RenameView::generate()
{
    //Pobieramy dane
    QString regex = ui->centralwidget->findChild<QLineEdit*>("m_regexEdit")->text();
    QString toName = ui->centralwidget->findChild<QLineEdit*>("m_toNameEdit")->text();
    try {
        RenameModel(regex, toName, m_directory.path());
    } catch (std::runtime_error &e)
    {
        ui->statusEdit->setText(e.what());
    }
}
