#include <string>
#include <iostream>

int main() {
    using namespace std;
    string s1("To "), s2("jest "), s3("string.");
    s1 += s2;  /* Konkatenacja. */
    string s4 = s1 + s3;
    cout << s4 << endl;
    string s5("Jego rozmiar to: ");
    cout << s5 << s4.length() << endl;
    cout << "Wpisz zdanie: " << endl;
    getline(cin, s2);   /* s2 zapamięta całą linię. */
    cout << "Oto Twoje zdanie: \n" << s2 << endl;
    cout << "Jego rozmiar to: " << s2.length() << endl;
    return 0;
}
