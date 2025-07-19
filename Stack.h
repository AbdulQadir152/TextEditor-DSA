#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
    T* arr;
    int top;
    int size;

public:
    Stack(int size = 100)
    {
        this->size = size;
        top = -1;
        arr = new T[size];
    }

    void push(T value)
    {
        if(top < size - 1)
            arr[++top] = value;
        else
            cout << "Stack Overflow" << endl;
    }

    T pop()
    {
        if(top >= 0)
            return arr[top--];
        else
        {
            cout << "Stack Underflow" << endl;
            return nullptr;
        }
    }

    T peek() const
    {
        if(top >= 0 && top < size)
            return arr[top];
        else
            return nullptr;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

#endif
