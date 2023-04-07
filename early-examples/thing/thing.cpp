#include "thing.h"
#include <QTextStream>
using namespace Qt;

void Thing::set(int num, char c) {
    m_Number = num;
    m_Character = c;
}

void Thing::increment() {
    ++m_Number;
    ++m_Character;
}

void Thing::show() {
    QTextStream cout(stdout);
    cout << m_Number << '\t' << m_Character << endl;
}

int Thing::get_m_Number()
{
    return m_Number;
}

char Thing::get_m_Character()
{
    return m_Character;
}

