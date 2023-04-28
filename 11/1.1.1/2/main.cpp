#include <QDebug>
#include <QObject>
#include <QWidget>

template <class T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 25;
    qDebug() << a << " " << b;
    swap(a, b);
    qDebug() << a << " " << b;

    QString tekst1 = "hello";
    QString tekst2 = "goodbye";
    qDebug() << tekst1 << " " << tekst2;
    swap(tekst1, tekst2);
    qDebug() << tekst1 << " " << tekst2;

    int *toA = &a;
    int *toB = &b;
    qDebug() << *toA << " " << *toB;
    swap(toA, toB);
    qDebug() << *toA << " " << *toB;

    QWidget* object1 = new QWidget();
    QWidget* object2 = new QWidget();
    qDebug() << object1 << " " << object2;
    //swap(object1, object2);
    qDebug() << object1 << " " << object2;
}
