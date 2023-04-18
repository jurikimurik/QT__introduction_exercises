/********************************************************************************
** Formularz wygenerowany w oparciu o plik UI 'ProductForm.ui'
**
** OSTRZEŻENIE! Wszelkie zmiany wprowadzone do tego pliku zostaną utracone po ponownej kompilacji pliku UI!
********************************************************************************/

#ifndef UI_PRODUCTFORM_H
#define UI_PRODUCTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE
//start
class Ui_ProductForm
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *priceSpinbox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *nameLineEdit;
    QLabel *label_4;
    QTextEdit *descriptionEdit;
    QDateEdit *dateEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ProductForm)
//end
    {
        if (ProductForm->objectName().isEmpty())
            ProductForm->setObjectName(QString::fromUtf8("ProductForm"));
        ProductForm->resize(257, 209);
        verticalLayout = new QVBoxLayout(ProductForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(ProductForm);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        priceSpinbox = new QDoubleSpinBox(ProductForm);
        priceSpinbox->setObjectName(QString::fromUtf8("priceSpinbox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, priceSpinbox);

        label_2 = new QLabel(ProductForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(ProductForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        nameLineEdit = new QLineEdit(ProductForm);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        label_4 = new QLabel(ProductForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        descriptionEdit = new QTextEdit(ProductForm);
        descriptionEdit->setObjectName(QString::fromUtf8("descriptionEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, descriptionEdit);

        dateEdit = new QDateEdit(ProductForm);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(ProductForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(priceSpinbox);
#endif // QT_NO_SHORTCUT

        retranslateUi(ProductForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), ProductForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ProductForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(ProductForm);
    } // setupUi

    void retranslateUi(QDialog *ProductForm)
    {
        ProductForm->setWindowTitle(QApplication::translate("ProductForm", "Formularz produktu", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProductForm", "&Cena", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ProductForm", "Opis", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ProductForm", "Termin przydatności", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ProductForm", "Nazwa", 0, QApplication::UnicodeUTF8));
    } // retranslateUi
//start
};
namespace Ui {
    class ProductForm: public Ui_ProductForm {};
} // namespace Ui
//end
QT_END_NAMESPACE

#endif // UI_PRODUCTFORM_H
