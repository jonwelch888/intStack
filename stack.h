#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10
#include <stdexcept>


class Stack {
private:
    int arr[STACK_SIZE];
    int top;

public:
    Stack();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
};

#endif // STACK_H

