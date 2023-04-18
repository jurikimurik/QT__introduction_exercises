#include <QTextStream> 
#include "student.h"

static QTextStream cout(stdout); 

void finish(Student* student) {
    cout << "\nNastępujący "
         << student->getClassName()
         << " wnioskuje o tytuł.\n "
         << student->toString() << "\n";
}

int main() {
    Undergrad us("Frodo Baggins", 5562, "Teoria pierścieni", 4, 1220);
    GradStudent gs("Bilbo Baggins", 3029, "Historia", 6,
                    GradStudent::fellowship);
    cout << "Oto dane naszych dwóch studentów:\n";
    cout << gs.toString() << endl;
    cout << us.toString() << endl;
    cout << "\nOto co się stanie, gdy obaj skończą studia:\n";
    finish(&us);
    finish(&gs);
    return 0;
}
