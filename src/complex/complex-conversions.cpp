// #include "complex.h"

int main() {
    Complex c1 (4.5, 1.2);
    Complex c2 (3.6, 1.5);
    
    Complex c3 = c1 + c2;
    Complex c4 = c3 + 1.4; /* Promocja prawego argumentu. */
    Complex c5 = 8.0 - c4; /* Promocja lewego argumentu. */
    Complex c6 = 1.2 + c4; /* Błąd: lewy argument nie zostanie wypromowany 
				w przypadku operatorów będących składowymi. */
}

