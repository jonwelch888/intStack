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

    const int MAX_OPERATIONS = 100;
    int operation;

    for (int i = 0; i < MAX_OPERATIONS; i++) {
        int stackSize = stack.size();  // Assuming 'size' is a method that returns the current number of elements
        double fullnessRatio = double(stackSize) / STACK_SIZE;

        // Define operation probabilities based on stack fullness
        double pushProb = 1.0 - fullnessRatio;  // Higher chance to push if not full
        double popProb = fullnessRatio;         // Higher chance to pop if not empty
        double peekProb = 0.1;                  // Constant small chance to peek

        // Normalize probabilities to sum to 1
        double totalProb = pushProb + popProb + peekProb;
        pushProb /= totalProb;
        popProb /= totalProb;
        peekProb /= totalProb;

        // Randomly decide the next operation
        double randValue = (double)rand() / RAND_MAX;

        if (randValue < pushProb) {
            // Try to push a random value
            if (!stack.push(rand() % 100)) {
                std::cout << "Failed to push: Stack is full\n";
            } else {
                std::cout << "Pushed a value successfully\n";
            }
        } else if (randValue < pushProb + popProb) {
            // Try to pop
            try {
                int poppedValue = stack.pop();
                std::cout << "Popped: " << poppedValue << "\n";
            } catch (const std::underflow_error& e) {
                std::cout << "Failed to pop: " << e.what() << "\n";
            }
        } else {
            // Try to peek
            try {
                int peekedValue = stack.peek();
                std::cout << "Peeked: " << peekedValue << "\n";
            } catch (const std::underflow_error& e) {
                std::cout << "Failed to peek: " << e.what() << "\n";
            }
        }
    }

    return 0;
}
