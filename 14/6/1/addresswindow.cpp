#include "addresswindow.h"
#include "ui_addresswindow.h"

#include "countryprops.h"

AddressWindow::AddressWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddressWindow)
{
    ui->setupUi(this);
    //Dla make_pair
    using namespace std;

    //Inicjalizacja zmiennych
    //  - COUNTRY
    QComboBox* m_countryBox = ui->infoWidget->findChild<QComboBox*>("m_countryBox");
    QLabel* m_countryLabel =  ui->infoWidget->findChild<QLabel*>("m_countryLabel");
    m_countryPair = make_pair(m_countryLabel, m_countryBox);
    //  - ADDRESS
    QLabel* m_addressLabel = ui->infoWidget->findChild<QLabel*>("m_addressLabel");
    QLineEdit* m_addressEdit =  ui->infoWidget->findChild<QLineEdit*>("m_addressEdit");
    m_addressPair = make_pair(m_addressLabel, m_addressEdit);
    //  - CITY
    QLabel* m_cityLabel = ui->infoWidget->findChild<QLabel*>("m_cityLabel");
    QLineEdit* m_cityEdit =  ui->infoWidget->findChild<QLineEdit*>("m_cityEdit");
    m_cityPair = make_pair(m_cityLabel, m_cityEdit);
    //  - NAME
    QLabel* m_nameLabel = ui->infoWidget->findChild<QLabel*>("m_nameLabel");
    QLineEdit* m_nameEdit =  ui->infoWidget->findChild<QLineEdit*>("m_nameEdit");
    m_namePair = make_pair(m_nameLabel, m_nameEdit);
    //  - PHONE
    QLabel* m_phoneLabel = ui->infoWidget->findChild<QLabel*>("m_phoneLabel");
    QLineEdit* m_phoneEdit =  ui->infoWidget->findChild<QLineEdit*>("m_phoneEdit");
    m_phonePair = make_pair(m_phoneLabel, m_phoneEdit);
    //  - STATE
    QLabel* m_stateLabel = ui->infoWidget->findChild<QLabel*>("m_stateLabel");
    QLineEdit* m_stateEdit =  ui->infoWidget->findChild<QLineEdit*>("m_stateEdit");
    m_statePair = make_pair(m_stateLabel, m_stateEdit);
    //  - ZIP
    QLabel* m_zipLabel = ui->infoWidget->findChild<QLabel*>("m_zipLabel");
    QLineEdit* m_zipEdit =  ui->infoWidget->findChild<QLineEdit*>("m_zipEdit");
    m_zipPair = make_pair(m_zipLabel, m_zipEdit);

    // Przyciski
    m_okButton = ui->buttonsWidget->findChild<QPushButton*>("m_okButton");
    m_cancelButton = ui->buttonsWidget->findChild<QPushButton*>("m_cancelButton");

    // Inicjalizacja typu USA i dodanie do QComboBox
    CountryProps USA("USA");
    m_countryProperties.push_back(USA);
    CountryProps Canada("Canada");
    m_countryProperties.push_back(Canada);

    for(const auto& elem : m_countryProperties)
    {
        m_countryPair.second->addItem(elem.getC_countryName());
    }

    //Wybieramy i ustawiamy pierwsza opcję
    countryChanged(m_countryProperties.first().getC_countryName());
}

AddressWindow::~AddressWindow()
{
    delete ui;
}

void AddressWindow::proceed()
{
    qDebug() << "void AddressWindow::proceed()";
}

void AddressWindow::countryChanged(QString name)
{
    qDebug() << "AddressWindow::countryChanged(QString name = " + name + ")";
}

void AddressWindow::cancel()
{
    qDebug() << "void AddressWindow::cancel()";
}
