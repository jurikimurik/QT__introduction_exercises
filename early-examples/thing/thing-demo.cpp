#include <QTextStream>
#include "thing.h"
using namespace Qt;

void display(Thing t, int n) {
    int i;
    for(i = 0; i < n; ++i)
        t.show();
}

int main()
{
    QTextStream cout(stdout);
    Thing t1, t2;
    t1.set(23, 'H');
    t2.set(1234, 'w');
    t1.increment();
    // Ten jest po prostu prywatny, wiec brak dostepu
    //cout << t1.m_Number;

    // inny sposob (podpunkt b)
    cout << t1.get_m_Number() << endl;

    display(t1, 3);
    // A o tym totalnie nic nie wie (nie wie skad sie wzal), wiec zglasza blad
    //cout<< i << endl;
    t2.show();
    return 0;
}
