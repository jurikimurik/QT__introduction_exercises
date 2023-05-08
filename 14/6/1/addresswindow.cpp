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

    // Inicjalizacja typu USA oraz Kanady i dodanie do QComboBox
    //  - "USA"
    CountryProps USA("USA");
    USA.set(Type::Zip, "Zip-Code", R"([0-9]{2}-*[0-9]{3})");
    USA.set(Type::State, "State", "[a-zA-Z]{2}");
    m_countryProperties.push_back(USA);
    //  - "CANADA"
    CountryProps Canada("Canada");
    Canada.set(Type::State, "State", "[A-Z]{2}");
    Canada.set(Type::Zip, "Postal Code", R"(([A-Z])([0-9])\g<1> ?\g<2>\g<1>\g<2>)");
    m_countryProperties.push_back(Canada);
    //  - "POLAND"
    CountryProps Poland("Poland");
    Poland.set(Type::Zip, "Postal Code", R"([0-9]{2}-*[0-9]{3})");
    Poland.set(Type::State, "Voivodeship", R"([^\s]+)");
    m_countryProperties.push_back(Poland);
    //  - "UKRAINE"
    CountryProps Ukraine("Ukraine");
    Ukraine.set(Type::Zip, "Postcode", R"([0-9]{2}-*[0-9]{3})");
    Ukraine.set(Type::State, "Region", R"(.* OBL.)");
    m_countryProperties.push_back(Ukraine);

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
    //Sprawdzamy poprawnosc
    if(!m_addressPair.second->hasAcceptableInput() ||
        !m_cityPair.second->hasAcceptableInput() ||
        !m_namePair.second->hasAcceptableInput() ||
        !m_phonePair.second->hasAcceptableInput() ||
        !m_statePair.second->hasAcceptableInput() ||
        !m_zipPair.second->hasAcceptableInput()) {
        QMessageBox::warning(this, "UWAGA", "Pola zawieraja niepoprawny/niedokonczony tekst. Prosze sprawdzic go ponownie.", "Ok");
        return;
    }

    QString allInOneText;
    allInOneText += m_countryPair.second->currentText() + "\n";
    allInOneText += m_statePair.second->text() + " " + m_zipPair.second->text() + " " + m_cityPair.second->text() + "\n";
    allInOneText += m_addressPair.second->text() + "\n";
    allInOneText += m_namePair.second->text() + " " + m_phonePair.second->text() + "\n";

    QMessageBox::information(this, "List", allInOneText, "Wyslac list","Zaczekaj!");


}

void AddressWindow::countryChanged(QString name)
{
    cancel();

    qDebug() << "AddressWindow::countryChanged(QString name = " + name + ")";
    CountryProps country("NONE");
    for(const auto& elem : m_countryProperties)
        if(elem.getC_countryName() == name) {
            country = elem;
            break;
        }

    // Jezeli nie znaleziona
    if(country.getC_countryName() == "NONE")
        return;

    qDebug() << "DZIALAMY";

    // Ustawiamy prawidlowo etykiety oraz walidatory
    //  - ADDRESS
    QPair<QString, QString> data = country.value(Type::Address);
    m_addressPair.first->setText(data.first);
    m_addressPair.second->setValidator(new QRegularExpressionValidator(
                                    QRegularExpression(data.second),
                                        m_addressPair.second));
    //  - CITY
    data = country.value(Type::City);
    m_cityPair.first->setText(data.first);
    m_cityPair.second->setValidator(new QRegularExpressionValidator(
        QRegularExpression(data.second),
        m_cityPair.second));
    //  - NAME
    data = country.value(Type::Name);
    m_namePair.first->setText(data.first);
    m_namePair.second->setValidator(new QRegularExpressionValidator(
        QRegularExpression(data.second),
        m_namePair.second));
    //  - PHONE
    data = country.value(Type::Phone);
    m_phonePair.first->setText(data.first);
    m_phonePair.second->setValidator(new QRegularExpressionValidator(
        QRegularExpression(data.second),
        m_phonePair.second));
    //  - STATE
    data = country.value(Type::State);
    m_statePair.first->setText(data.first);
    m_statePair.second->setValidator(new QRegularExpressionValidator(
        QRegularExpression(data.second),
        m_statePair.second));
    //  - ZIP
    data = country.value(Type::Zip);
    m_zipPair.first->setText(data.first);
    m_zipPair.second->setValidator(new QRegularExpressionValidator(
        QRegularExpression(data.second),
        m_zipPair.second));
    //  - COUNTRY
    data = country.value(Type::Country);
    m_countryPair.first->setText(data.first);
}

void AddressWindow::cancel()
{
    // Oczyszczamy tekst
    qDebug() << "void AddressWindow::cancel()";
    m_addressPair.second->setText("");
    m_cityPair.second->setText("");
    m_namePair.second->setText("");
    m_phonePair.second->setText("");
    m_statePair.second->setText("");
    m_zipPair.second->setText("");
}
