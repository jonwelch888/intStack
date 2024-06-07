/* **************************************
Name: Jon Welch
Assignment: 4
Purpose of the file: This header file contains the 
declaration of the Stack class.
@note [stack.h] talks to [stack.cpp], & [main.h];
*************************************** */

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10
#define CHOICES 6
#define RMULTIPLIER 10
#define HUND 100
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
    /* *********************
    constructors/destructor
    ********************** */
    Stack();
    /* *********************
    Accessors
    ********************** */
    int pop();
    int peek();
    bool isEmpty();

    /**********************
    Mutators
    ***********************/
    bool push(int value);

};

#endif // STACK_H

