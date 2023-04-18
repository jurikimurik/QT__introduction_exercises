// Mile są przeliczane na kilometry
#include <QTextStream>

QTextStream cin(stdin);
QTextStream cout(stdout);
QTextStream cerr(stderr);

const double  m2k = 1.609;    // stała konwersji

inline double mi2km(int miles) {
    return (miles * m2k);
}

int main() {
    int  miles;
    double kilometers;
    cout << "Wprowadź odległość w milach: " << flush;
    cin >> miles ;  
    kilometers = mi2km(miles);
    cout << "To w przybliżeniu "
         <<  static_cast<int>(kilometers)
         << "km."<< endl;
    cout << "Bez rzutowania, kilometry = "
         << kilometers << endl;
    double* dp = const_cast<double*>(&m2k); 
    cout << "m2k: " << m2k << endl;
    cout << "&m2k: " << &m2k << "  dp: " << dp << endl;
    cout << "*dp: " << *dp << endl; 
    *dp = 1.892; /*Co próbujemy tutaj zrobić?*/
    cout << "Czy dotrzemy do tej instrukcji? " << endl;
    return 0;
}

/*WYNIK
Wprowadź odległość w milach: 23
To w przybliżeniu 37km.
Bez rzutowania, kilometry = 37.007
m2k: 1.609
&m2k: 0x8049048  dp: 0x8049048
*dp: 1.609
*/

