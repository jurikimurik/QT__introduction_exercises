#ifndef STACK_H
#define STACK_H

#include <QDebug>
template<class T> class Node {
public:
    Node(T invalue): m_Value (invalue), m_Next(nullptr) {}
    ~Node();
    T getValue() const {return m_Value;}
    void setValue(T value) {m_Value = value;}
    Node<T>* getNext() const {return m_Next;}
    void setNext(Node<T>* next) {m_Next = next;}
private:
    T m_Value;
    Node<T>* m_Next;
};

template<class T> Node<T>::~Node() {
    qDebug() << m_Value << " usuniety " << Qt::endl;
    if(m_Next) {
        delete m_Next;
    }
}

template <class T> class Stack {
public:
    Stack(): m_Head(nullptr), m_Count(0) {}
    ~Stack<T>() {delete m_Head;}
    void push(const T& t);
    T pop();
    T top() const;
    int count() const;
private:
    Node<T>* m_Head;
    int m_Count;
};


template<class T>
void Stack<T>::push(const T &value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->setNext(m_Head);
    m_Head = newNode;
    ++m_Count;
}

template<class T>
T Stack<T>::pop()
{
    Node<T>* popped = m_Head;
    if(m_Head != 0) {
        m_Head = m_Head->getNext();
        T retval = popped->getValue();
        popped->setNext(nullptr);
        delete popped;
        --m_Count;
        return retval;
    }
    return 0;
}

template<class T>
T Stack<T>::top() const
{
    return *m_Head;
}

template<class T>
int Stack<T>::count() const
{
    return m_Count;
}

///////////////////////////////////////////////////////////////////////////////////////////////


template <class T> class Queue {
public:
    Queue(): m_Oldest(nullptr), m_LastOne(nullptr), m_Count(0) {}
    ~Queue<T>() {delete m_Oldest;}
    void push(const T& t);
    T pop();
    T top() const;
    int count() const;
private:
    Node<T>* m_Oldest;
    Node<T>* m_LastOne;
    int m_Count;
};

template<class T>
void Queue<T>::push(const T &value)
{
    Node<T>* newNode = new Node<T>(value);
    //JEZELI PIERWSZY
    if(m_Oldest == nullptr)
        m_Oldest = newNode;
    else
        m_LastOne->setNext(newNode);
    m_LastOne = newNode;
    ++m_Count;
}

template<class T>
T Queue<T>::pop()
{
    Node<T>* popped = m_Oldest;
    if(m_Oldest != nullptr) {
        m_Oldest = m_Oldest->getNext();
        T retval = popped->getValue();
        popped->setNext(nullptr);
        delete popped;
        --m_Count;
        return retval;
    }
    return 0;
}

template<class T>
int Queue<T>::count() const
{
    return m_Count;
}
#endif // STACK_H
