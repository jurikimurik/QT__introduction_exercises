#include <iostream>
using namespace std;
//start id=classdef
class SignatureDemo {
public:
    SignatureDemo(int val) : m_Val(val) {}
    void demo(int n)
        {cout << ++m_Val << "\tdemo(int)" << endl;}
    void demo(int n) const                             /* Przeładowane przez const. */  
        {cout << m_Val << "\tdemo(int) const" << endl;}
/*  void demo(const int& n)   
      {cout << ++m_Val << "\tdemo(int&)" << endl;}  */ /* Konflikt z poprzednią funkcją. */
    void demo(short s)  
        {cout << ++m_Val << "\tdemo(short)" << endl;}
    void demo(float f)  
        {cout << ++m_Val << "\tdemo(float)" << endl;}
    void demo(float f) const 
        {cout << m_Val << "\tdemo(float) const" << endl;}
    void demo(double d)
        {cout << ++m_Val << "\tdemo(double)" << endl;}
private:
    int m_Val;
};
//end
//start id=clientcode
int main() {
    SignatureDemo sd(5);
    const SignatureDemo csd(17);
    sd.demo(2);    
    csd.demo(2);   /* Wywołana zostanie wersja const. */
    int i = 3;
    sd.demo(i);
    short s = 5;
    sd.demo(s);
    csd.demo(s);   /* Nie może zostać wywołana wersja short, 
			która nie jest const, zatem wymagana jest promocja 
			do int w celu wywołania wersji const int. */
    sd.demo(2.3);  /* To double, a nie float. */
    float f(4.5);   
    sd.demo(f);
    csd.demo(f);    
    // csd.demo(4.5);  
    return 0;
}
//end
