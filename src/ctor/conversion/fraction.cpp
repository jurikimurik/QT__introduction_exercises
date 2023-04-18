class Fraction {
public:
    Fraction(int n)                  /* Konstruktor jednoargumentowy definiuje konwersję z int. */
       : m_Numer(n), m_Denom(1) {}
    Fraction(int n, int d )
       : m_Numer(n), m_Denom(d) {}
    Fraction times(const Fraction& other) {
       return Fraction(m_Numer * other.m_Numer, m_Denom * other.m_Denom);
    }
private:
    int m_Numer, m_Denom;
};
int main() {
    int i;
    Fraction frac(8);                /* Wywołanie konstruktora konwertującego. */
    Fraction frac2 = 5;              /* Kopiowanie int (również wywołuje konstruktor konwertujący). */
    frac = 9;                        /* Konwersja z przypisaniem. */
    frac = (Fraction) 7;             /* Rzutowanie w stylu C (przestarzałe). */
    frac = Fraction(6);              /* Jawny element pośredni; rzutowanie w stylu C++.*/
    frac = static_cast<Fraction>(6); /* Preferowane rzutowanie w stylu ANSI. */
    frac = frac2.times(19);          /* Jawne wywołanie konstruktora konwertującego.*/
    return 0;
}
