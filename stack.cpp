/* ***********************************************************
Name: Jon Welch
Assignment: 4
Purpose of the file: This source file contains the implementation
of the Stack class.
************************************************************* */

#include "stack.h"

/* ***********************************************************
Default constructor for Stack class. Initializes the top index to -1.
************************************************************* */
Stack::Stack() : top(-1){}

void Stack::push(int value)
{
    /* *******************************************************************
    This function pushes a value onto the stack.

    @param (int) value : Value to be pushed onto the stack.

    @exception std::overflow_error : Thrown when attempting to push onto a full stack.
    ********************************************************************** */
    if (top >= STACK_SIZE - 1)
    {
        throw std::overflow_error("Stack overflow");
    }
    arr[++top] = value;
}

int Stack::pop()
{
    /* ***********************************************************
    This function pops a value from the stack.

    @return (int) : Value popped from the stack.

    @exception std::underflow_error : Thrown when attempting to pop from an empty stack.
    ************************************************************* */
    if (top < 0)
    {
        throw std::underflow_error("Stack underflow");
    }
    return arr[top--];
}

int Stack::peek()
{
    /* ***********************************************************
    This function returns the top value from the stack without removing it.

    @return (int) : Top value of the stack.

    @exception std::underflow_error : Thrown when attempting to peek into an empty stack.
    ************************************************************* */
    if (top < 0)
    {
        throw std::underflow_error("Stack underflow");
    }
    return arr[top];
}

bool Stack::isEmpty()
{
    /* ***********************************************************
    This function checks if the stack is empty.

    @return (bool) : True if the stack is empty, false otherwise.
    ************************************************************* */
    return top == -1;
}

