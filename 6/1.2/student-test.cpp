#include <QTextStream>
#include "student.h"
using namespace Qt;

static QTextStream cout(stdout);

void finish(Student* student) {
    cout << "\nNastepujacy "
         << student->getClassName()
         << " wnioskuje o tytul.\n"
         << student->toString() << "\n";
}

int main()
{
    Undergrad us("Frodo Baggins", 5562, "Teoria Pierscieni", 4, 1220);
    GradStudent gs("Bilbo Baggins", 3029, "Historia", 6, GradStudent::fellowship);
    cout << "Oto dane naszych dwoch studentow:\n";
    cout << gs.toString() << endl;
    cout << us.toString() << endl;
    cout << "\nOto co sie stanie, gdy obaj skoncza studia:\n";
    finish(&us);
    finish(&gs);
    return 0;
}
