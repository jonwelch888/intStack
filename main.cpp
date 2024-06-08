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

    // Testing all operations when the stack is initially empty
    std::cout << "Testing Empty State:\n";
    try { stack.pop(); } catch (const std::exception& e) { std::cout << "Pop on empty: " << e.what() << '\n'; }
    try { stack.peek(); } catch (const std::exception& e) { std::cout << "Peek on empty: " << e.what() << '\n'; }
    std::cout << "IsEmpty: " << (stack.isEmpty() ? "True" : "False") << '\n';
    stack.push(rand() % 100); // Pushing one element to change state

    // Testing all operations when the stack is partially full
    std::cout << "\nTesting Partially Full State:\n";
    stack.push(rand() % 100);
    std::cout << "Peek: " << stack.peek() << '\n';
    std::cout << "Pop: " << stack.pop() << '\n';
    std::cout << "IsEmpty: " << (stack.isEmpty() ? "True" : "False") << '\n';

    // Fill the stack to capacity to test the full state
    while (stack.push(rand() % 100)); // This loop will exit when push returns false (stack is full)
    std::cout << "\nTesting Full State:\n";
    try { stack.push(rand() % 100); } catch (const std::exception& e) { std::cout << "Push on full: " << e.what() << '\n'; }
    std::cout << "Peek: " << stack.peek() << '\n';
    std::cout << "Pop: " << stack.pop() << '\n';
    std::cout << "IsEmpty: " << (stack.isEmpty() ? "True" : "False") << '\n';

    return 0;
}
