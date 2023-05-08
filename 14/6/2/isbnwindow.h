#ifndef ISBNWINDOW_H
#define ISBNWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "isbnvalidator.h"

namespace Ui {
class ISBNWindow;
}

class ISBNWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ISBNWindow(QWidget *parent = nullptr);
    ~ISBNWindow();

public slots:
    void checkISBN();

private:
    Ui::ISBNWindow *ui;
    QLineEdit* m_ISBNEdit;
    QLineEdit* m_statusEdit;
};

#endif // ISBNWINDOW_H
