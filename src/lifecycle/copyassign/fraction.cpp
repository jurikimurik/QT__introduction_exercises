#include "fraction.h"
#include <assert.h>

//start
int Fraction::s_assigns = 0;     /* Statyczne definicje składowych. */
int Fraction::s_copies = 0;
int Fraction::s_ctors = 0;

Fraction::Fraction(const Fraction& other)
   :  m_Numer(other.m_Numer), m_Denom(other.m_Denom) {
   ++s_copies;
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {        /* Przeładowany operator=() nie powinien wykonywać żadnej akcji podczas przypisywania wartości samej sobie. */
        m_Numer = other.m_Numer;
        m_Denom = other.m_Denom;
        ++s_assigns;
    }
    return *this;                /* Przeładowany operator=() powinien zawsze zwracać *this, by pozwolić na łączenie wywołań w łańcuchy, np. a=b=c. */
}
//end

Fraction::Fraction(int n, int d) : m_Numer(n), m_Denom(d) {
   assert(m_Denom != 0);
   ++s_ctors;
}

Fraction Fraction::multiply(Fraction f2) {
   return Fraction (m_Numer*f2.m_Numer, m_Denom*f2.m_Denom);
}

QString Fraction::report() {
   return QString(" [assigns: %1 copies: %2 ctors: %3] ")
        .arg(s_assigns).arg(s_copies).arg(s_ctors);
}

