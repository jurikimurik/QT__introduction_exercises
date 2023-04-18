#include "shoppinglist.h"

QString ShoppingList::s_Check("[ ] ");

QStringList& ShoppingList::operator<<(const QString& newitem) {
    append(s_Check + newitem);
    return *this;
}

QString ShoppingList::makePrintList() {
    sort();
    prepend("****** lista zakup�w *******");
    return join("\n");
}
