#include <iostream>
using namespace std;

class A {
public:
    virtual void foo() {
        cout << "foo() z klasy A" << endl;
    }
};

class B: public A {
public:
    void foo() {
        cout << "foo() z klasy B" << endl;
    }
};

class C: public B {
public:
    void foo() {
        cout << "foo() z klasy C" << endl;
    }
};


int main() {
    C cobj;
    B *bptr = &cobj;
    bptr->foo();
    A* aptr = &cobj;
    aptr->foo();
}