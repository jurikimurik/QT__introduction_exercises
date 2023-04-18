#include <QInputDialog>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>

#include <cstdlib>
#include "shoppinglist.h"

void loadShoppingList(ShoppingList& slst) {

    bool ok;
    QString dept, item, qty, more;
    QStringList dptlst, yesno;
    dptlst << "Nabiał" << "Mięso" << "Warzywa"
           << "Mrożonki" << "Produkty gospodarstwa domowego"
           << "Żywność w puszkach" << "Przyprawy";
    yesno << "yes" << "no";
    do {
        dept = QInputDialog::
            getItem(NULL, "ShoppingListApp", "Dept:",
                    dptlst, 0, true, &ok);

        item = QInputDialog::
            getText(NULL, QString("ShoppingListApp"),
                    QString("Item:"), QLineEdit::Normal,
                    QString(), &ok);

        qty = QInputDialog::
            getText(NULL, "ShoppingListApp", "Ilość:",
                    QLineEdit::Normal, QString(), &ok);

        slst << QString("%1 - %2 - {%3}").arg(dept)
            .arg(item).arg(qty);
        more = QInputDialog::
            getItem(NULL, "ShoppingListApp", "Inny produkt? ",
                    yesno, 0, false, &ok);
    } while (more == "yes");
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);


    app.setQuitOnLastWindowClosed(false) ; /* jest to wymagane, 
      jeśli nie ma głównego okna QMainWindow i otwieramy
	  bądź zamykamy okna dialogowe. */

    ShoppingList shplst;
    loadShoppingList(shplst);
    qDebug() << "Wyślij listę do drukarki:\n\n";
    qDebug() << shplst.makePrintList();
    return 0;
}

