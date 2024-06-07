/* ***********************************************************
Name: Jon Welch
Assignment: 4
Purpose of the file: This source file contains the main function
to test the Stack class.
************************************************************* */

#include "main.h"

int main()
{
    /* ***********************************************************
    this main function serves as the entry point for the program. It 
    tests the functionality of the Stack class by performing various 
    operations, such as pushing, popping, peeking, and checking for 
    overflow and underflow conditions.

    Operations performed:
    1. pushing elements onto the stack until it is full.
    2. attempting to push another element to test stack overflow.
    3. peeking and popping all elements from the stack.
    4. attempting to pop from an empty stack to test stack underflow.
    5. additional tests for pushing, peeking, and popping a single element.
    6. randomized tests to ensure robustness.
    ************************************************************* */
    Stack stack;
    srand(static_cast<unsigned int>(time(0)));

    try
    {
        for (int i = 0; i < STACK_SIZE; i++)
        {
            stack.push(i);
            std::cout << "Pushed: " << i << std::endl;
        }
        try
        {
            stack.push(100);
        }
        catch (const std::overflow_error& e)
        {
            std::cerr << "Expected overflow error: " << e.what() << std::endl;
        }
        while (!stack.isEmpty())
        {
            std::cout << "Peek: " << stack.peek() << ", Pop: " << stack.pop() << std::endl;
        }
        
        try
        {
            stack.pop();
        }
        catch(const std::underflow_error& e)
        {
            std::cerr <<"expected underflow error: "<<e.what()<<std::endl;
        }

        stack.push(42);// extra tests 
        std::cout<<"pushed: 42"<<std::endl;
        std::cout<<"Peek: "<<stack.peek()<<", Pop: "<<stack.pop()<<std::endl;

        try
        {
            std::cout<<"pop from empty stack: ";
            stack.pop();
        }
        catch (const std::underflow_error& e)
        {
            std::cerr << "Expected underflow error: " << e.what() << std::endl;
        }
        //random test
        std::cout<<"\n ---- random test"<<std::endl;
        for(int i=0; i<100; i++)
        {
            int test = (rand()%2); // random choose push or pop;
            if(test ==0 && stack.isEmpty())
            {
                cobtinue; // skip pop test if stack is empty
            }
            if(test ==0)
            {
                try
                {
                    int value = (rand()%100);
                    stack.push(value);
                    std::cout<<"random push"<<value<<std::endl;
                }
                catch(const std::overflow_error& e)
                {
                    std::cerr<<"expeceted overflow error during random test: "<< e.what() <<std::endl;
                }
            else
            {
                    try
                    {
                        int value = stack.pop();
                        std::cout << "randomly popped: " << value << std::endl;
                    }
                    catch (const std::underflow_error& e)
                    {
                        std::cerr << "Expected underflow error during random operation: " << e.what() << std::endl;
                    }
            }
            }

        }    
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

