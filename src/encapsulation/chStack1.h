
#include <iostream>
#include <assert.h>
using namespace std;

// Implementacja ChStack z konstruktorem
const int DEFSIZE = 100;

class ChStack {
public:                                  //interfejs publiczny ADT ChStack
    explicit ChStack(int size):
    m_Maxlen(size), m_Top(EMPTY) {
        assert(size > 0);
        m_S = new char[size];
    }
    ChStack();                             // konstruktor domyślny
    ChStack(const ChStack& str);           // konstruktor kopiujący

    // transfer domen
    ChStack(int size, const char str[]);

    //destruktor
    ~ChStack() {
        delete []m_S;
    }

	// modyfikuje
    void reset() {
        m_Top = EMPTY;
    }                                      
	// modyfikuje
    void push(char c) {
        m_S[++m_Top]= c;
    }                                      
	// modyfikuje
    char pop() {
        return m_S[m_Top--];
    }                                      
	// metoda dostępowa
    char top_of() const {
        return m_S[m_Top];
    }                                      
	// metoda dostępowa
    bool isEmpty() const                   
    {
        return (m_Top == EMPTY);
    }

	// metoda dostępowa
    bool isFull() const                    
    {
        return (m_Top == m_Maxlen - 1);
    }
private:
    enum  {EMPTY = -1};
    char*  m_S;                            //zmienione z from m_S[maxlen]
    int    m_Maxlen;
    int    m_Top;
};

//konstruktor domyślny ChStack
ChStack::ChStack(): m_S(new char[DEFSIZE]),
m_Maxlen(DEFSIZE), m_Top(EMPTY) {}

//transfer domen




ChStack::ChStack(int size, const char str[])
        : m_Maxlen(size) {
    int i;
    assert(size > 0);
    m_S = new char[size];
    for (i = 0; i < m_Maxlen && str[i]; ++i)
        m_S[i] = str[i];
    m_Top = --i;
}