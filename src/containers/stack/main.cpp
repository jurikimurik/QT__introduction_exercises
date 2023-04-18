#include <QDebug>
#include <QString>
#include "stack.h"

int main() {
    Stack<int> intstack1, intstack2;
    int val;
    for (val = 0; val < 4; ++val) {
        intstack1.push(val);
        intstack2.push(2 * val);
    }
    while (intstack1.count()) {
        val = intstack1.pop();
        qDebug() << val;
    }
    Stack<QString> stringstack;
    stringstack.push("Pierwszy włożony na stos");
    stringstack.push("Drugi włożony na stos");
    stringstack.push("Pierwszy zdjęty ze stosu");
    QString val2;
    while (stringstack.count()) {
        val2 = stringstack.pop();
        qDebug() << val2;
    }
    qDebug() << "Teraz intstack2 ulegnie autodestrukcji.";
    return 0;
}

