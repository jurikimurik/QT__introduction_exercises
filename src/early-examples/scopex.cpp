
#include <iostream>
using namespace std;

long x = 17; 
float y = 7.3;              /* Zakres: ________________ */
static int z = 11;          /* Zakres: ________________ */

class Thing {
    int m_Num;              /* Zakres: ________________ */
public:
    static int s_Count;     /* Zakres: ________________ */
    Thing(int n = 0) : m_Num(n) {++s_Count;}
    ~Thing() {--s_Count;}
    int getNum() { return m_Num; }
};

int Thing::s_Count = 0;
Thing t(11);

int fn(char c, int x) {     /* Zakres: ________________ */
    int z = 5;              /* Zakres: ________________ */
    double y = 6.933; 
    { char y;               /* Zakres: ________________ */
    Thing z(4);             /* Zakres: ________________ */
    y = c + 3; 
    ::y += 0.3;             /* Zakres: ________________ */
    cout << y << endl;      /* Zakres: ________________ */
    }
    cout << Thing::s_Count
         << endl;           /* Zakres: ________________ */
    y /= 3.0;               /* Zakres: ________________ */
    ::z++;                  /* Zakres: ________________ */
    cout << y << endl;
    return x + z;
}

int main() {
    int x, y = 10; 
    char ch = 'B';          /* Zakres: ________________ */
    x = fn(ch, y); 
    cout << x << endl; 
    cout << ::y << endl;    /* Zakres: ________________ */
    cout << ::x / 2 << endl;
    cout << ::z << endl;
}

