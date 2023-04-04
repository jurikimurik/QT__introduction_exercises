#include <random>
#include <QTextStream>
using namespace Qt;
using namespace std;

QTextStream cout(stdout);
QTextStream cin(stdin);

int main()
{
    cout << "Dawaj mi tu seed: " << flush;
    int seed;
    cin >> seed;

    default_random_engine dre(seed);
    uniform_int_distribution id;


    cout << "Twoje liczby losowe na życzenie: " << flush;
    for(int i = 0; i < 10; ++i)
    {
        cout << id(dre) << ", ";
    }
}
