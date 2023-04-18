
#include <iostream>
using namespace std;

class A {
public:
    virtual ~A() { }
    virtual void foo() {
        cout << "foo() z klasy A" << endl;
        bar();
    }
    virtual void bar() {
        cout << "bar() z klasy A" << endl;
    }
};

class B: public A {
public:
    void foo() {
        cout << "foo() z klasy B" << endl;
        A::foo();
    }
    void bar() {
        cout << "bar() z klasy B" << endl;
    }
};

int main() {
    B bobj;
    A *aptr = &bobj;
    aptr->foo();
    cout << "-------------" << endl;
    A aobj = *aptr;
    aobj.foo();
    cout << "-------------" << endl;
    aobj = bobj;
    aobj.foo();
    cout << "-------------"<< endl;
    bobj.foo();
}

