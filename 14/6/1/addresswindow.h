#ifndef ADDRESSWINDOW_H
#define ADDRESSWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>



namespace Ui {
class AddressWindow;
}

class AddressWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddressWindow(QWidget *parent = nullptr);
    ~AddressWindow();

private:
    Ui::AddressWindow *ui;

    // Pole dotyczace kraju jest unikalne
    QPair<QLabel*, QComboBox*> m_countryPair;

    //Wygodny typ pary laczacy QLabel i QLineEdit
    using QInputPair_t = QPair<QLabel*, QLineEdit*>;

    QInputPair_t m_addressPair;
    QInputPair_t m_cityPair;
    QInputPair_t m_namePair;
    QInputPair_t m_phonePair;
    QInputPair_t m_statePair;
    QInputPair_t m_zipPair;

    QPushButton* m_okButton;
    QPushButton* m_cancelButton;
};

#endif // ADDRESSWINDOW_H
