#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "w konstruktorze A" << endl;
        foo();
    }
    virtual void foo() {
        cout << "foo() A" << endl;
    }
};

class B: public A {
public:
    B() {
        cout << "w konstruktorze B" << endl;
    }
    void foo() {
        cout << "foo() B" << endl;
    }
};

class C: public B {
public:
    C() {
        cout << "w konstruktorze C" << endl;
    }

    void foo() {
        cout << "foo() C" << endl;
    }
};

int main() {
    C* cptr = new C;
    cout << "Po zakończeniu konstrukcji:" << endl;
    cptr->foo();
    return 0;
}
