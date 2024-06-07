/* ***********************************************************
Name: Jon Welch
Assignment: 4
Purpose of the file: This source file contains the main function
to test the Stack class.
************************************************************* */

#include "main.h"

int main()
{
    /* ********************************************************************************
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
    @note: attempting to test the minimum number of tests; [3 (states) * 4 (operations)= 12 tests] 
    *********************************************************************************** */
    Stack stack;
    srand(static_cast<unsigned int>(time(0)));

    int successfulPushes = 0;
    int successfulPops = 0;
    int overflowErrors = 0;
    int underflowErrors = 0;
    int peekSuccesses = 0;

    try
    {
        for (int i = 0; i < STACK_SIZE; i++)
        {
            stack.push(i);
            successfulPushes++;
        }

        // Test stack overflow
        try
        {
            stack.push(100);
        }
        catch (const std::overflow_error& e)
        {
            overflowErrors++;
        }

        // Test peeking and popping all elements
        while (!stack.isEmpty())
        {
            stack.peek();
            peekSuccesses++;
            stack.pop();
            successfulPops++;
        }

        // Test stack underflow
        try
        {
            stack.pop();
        }
        catch (const std::underflow_error& e)
        {
            underflowErrors++;
        }

        // Additional tests
        stack.push(42); // Extra tests 
        successfulPushes++;
        stack.peek();
        peekSuccesses++;
        stack.pop();
        successfulPops++;

        try
        {
            stack.pop();
        }
        catch (const std::underflow_error& e)
        {
            underflowErrors++;
        }

        // Randomized test using switch statement
        for (int i = 0; i < (STACK_SIZE * RMULTIPLIER); i++)
        {
            int value = rand() % HUND;
            int choice = rand() % CHOICES + 1;
            switch (choice)
            {
                case 1:
                case 2:
                    if (successfulPushes < STACK_SIZE)
                    {
                        // Attempt to push an element
                        if (!stack.push(value))
                        {
                            overflowErrors++;
                        }
                        else
                        {
                            successfulPushes++;
                        }
                    }
                    else
                    {
                        // Force overflow test
                        if (!stack.push(value))
                        {
                            overflowErrors++;
                        }
                    }
                    break;
                case 3:
                case 4:
                    if (!stack.isEmpty())
                    {
                        try
                        {
                            stack.pop();
                            successfulPops++;
                        }
                        catch (const std::underflow_error& e)
                        {
                            underflowErrors++;
                        }
                    }
                    break;
                case 5:
                    if (!stack.isEmpty())
                    {
                        try
                        {
                            stack.peek();
                            peekSuccesses++;
                        }
                        catch (const std::underflow_error& e)
                        {
                            underflowErrors++;
                        }
                    }
                    break;
                case 6:
                    break;
            }
        }

        // Print
        std::cout << "\n---- Test Summary ----test 5-" << std::endl;
        std::cout << "Successful pushes: " << successfulPushes << std::endl;
        std::cout << "Overflow errors: " << overflowErrors << std::endl;
        std::cout << "Successful pops: " << successfulPops << std::endl;
        std::cout << "Underflow errors: " << underflowErrors << std::endl;
        std::cout << "Peek successes: " << peekSuccesses << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
