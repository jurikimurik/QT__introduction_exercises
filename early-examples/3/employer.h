#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <iostream>
using namespace std;

class Person;
class Position;

class Employer
{
private:
    string m_Name;
    string m_market;
public:
    bool hire(Person& newHire, Position pos);
    Employer(string name, string market);
    string toString();
};

#endif // EMPLOYER_H
