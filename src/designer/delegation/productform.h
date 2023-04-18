#ifndef PRODUCTFORM_H
#define PRODUCTFORM_H
//start
#include <QDialog>
class Product;
class Ui_ProductForm;
class QWidget;
class QAbstractButton;

/**  Przykład integracji ui z Designerem -
     delegacja przez wskaźnik. */
class ProductForm : public QDialog {
        Q_OBJECT
public:
    explicit ProductForm(Product* product = 0, QWidget* parent=0); /* 1Oznaczone jako explicit 
				by uniknąć domniemanych konwersji pomiędzy wskaźnikami!  */
    void setModel(Product* model);

public slots:
    void accept();
    void commit();
    void update();

private:
    Ui_ProductForm *m_ui;
    Product* m_model;
};
//end
#endif        //  #ifndef PRODUCTFORM_H
