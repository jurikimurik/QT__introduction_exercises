#ifndef THING_H
#define THING_H


class Thing
{
public:
    void set(int num, char c);
    void increment();
    void show();

    int get_m_Number();
    char get_m_Character();
private:
    int m_Number;
    char m_Character;
};

#endif // THING_H
