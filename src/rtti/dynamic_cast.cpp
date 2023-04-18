#include <QVector>
#include <QAbstractButton>
#include <QDebug>
#include <QPushButton>
#include <QComboBox>
#include <QMenuBar>
#include <QCheckBox>
#include <QApplication>
#include <QDateTimeEdit>
#include <QDoubleSpinBox>

//start 
int processWidget(QWidget* wid) {
    
    if (wid->inherits("QAbstractSpinBox")) { /* Tylko dla QObject przetworzonego przez moc. */
        QAbstractSpinBox* qasbp = 
            static_cast <QAbstractSpinBox*> (wid);
        qasbp->setAlignment(Qt::AlignHCenter);
    }
    else {
        QAbstractButton* buttonPtr = 
            dynamic_cast<QAbstractButton*>(wid);
        if (buttonPtr) {                     /* Jeśli nie null, to poprawny QAbstractButton. */
            buttonPtr->click();
            qDebug() << QString("Nacisnąłem przycisk numer %1:")
                .arg(buttonPtr->text());
        }
        return 1;
    }
    return 0;
}
//end

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    //start
    QVector<QWidget*> widvect;

    widvect.append(new QPushButton("Ok"));
    widvect.append(new QCheckBox("Checked"));
    widvect.append(new QComboBox());
    widvect.append(new QMenuBar());
    widvect.append(new QCheckBox("With Fries"));
    widvect.append(new QPushButton("Nooo!!!!"));
    widvect.append(new QDateTimeEdit());
    widvect.append(new QDoubleSpinBox());
    foreach (QWidget* widpointer, widvect) {
        processWidget(widpointer);
    }
   return 0;
}
