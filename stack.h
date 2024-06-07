




#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10
#include <stdexcept>


class Stack
{
    /*********************************************
    This class defines a Stack of integers. It allows 
    pushing, popping, peeking, and checking if the stack 
    is empty.

    @attrib arr : the array storing the stack elements
    @attrib top : the index of the top element in the stack
    *********************************************/
private:

int arr[STACK_SIZE];
int top;

public:
/**********************
constructors/destructor
***********************/
Stack();
/**********************
Stack operations
***********************/
void push(int value);
int pop();
int peek();
bool isEmpty();
};

#endif // STACK_H

