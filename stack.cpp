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

bool Stack::push(int value)
{
    /* *******************************************************************
    This function pushes a value onto the stack.

    @param (int) value : Value to be pushed onto the stack.

    @return (bool) : True if the value is successfully pushed, false if the stack is full.
    ********************************************************************** */
    bool pushed = false;
    if (top < STACK_SIZE - 1)
    {
        arr[++top] = value;
        pushed = true;
    }
    return pushed;
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

int Stack::size()
{  // New method to return the number of elements in the stack
    return top + 1;
}
