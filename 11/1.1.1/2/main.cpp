#include <QDebug>
#include <QObject>
#include <QWidget>

template <class T>
void super_swap(T& a, T& b) {
    static_assert(std::is_copy_constructible<T>(), "Musi byc udostepniony operator przypisania");
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 25;
    qDebug() << a << " " << b;
    super_swap(a, b);
    qDebug() << a << " " << b;

    QString tekst1 = "hello";
    QString tekst2 = "goodbye";
    qDebug() << tekst1 << " " << tekst2;
    super_swap(tekst1, tekst2);
    qDebug() << tekst1 << " " << tekst2;

    int *toA = &a;
    int *toB = &b;
    qDebug() << *toA << " " << *toB;
    super_swap(toA, toB);
    qDebug() << *toA << " " << *toB;

    QObject* object1 = new QObject();
    QObject* object2 = new QObject();
    qDebug() << object1 << " " << object2;
    super_swap(object1, object2);
    qDebug() << object1 << " " << object2;

    QObject object3;
    QObject object4;
    qDebug() << &object3 << " " << &object4;
    super_swap(object3, object4);
    qDebug() << &object3 << " " << &object4;
}
