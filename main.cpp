 #include "main.h"

int main() {
    Stack stack;

    try {
        // Test pushing elements to the 
stack
        for (int i = 0; i < STACK_SIZE; ++i) 
{
            stack.push(i);
            std::cout << "Pushed: " << i << 
std::endl;
        }

        // Test stack overflow
        try {
            stack.push(100);
        } catch (const std::overflow_error& 
e) {
            std::cerr << "Expected overflow 
error: " << e.what() << std::endl;
        }

        // Test peeking and popping all 
elements
        while (!stack.isEmpty()) {
            std::cout << "Peek: " << 
stack.peek() << ", Pop: " << stack.pop() << 
std::endl;
        }

        // Test stack underflow
        try {
            stack.pop();
        } catch (const std::underflow_error& 
e) {
            std::cerr << "Expected underflow 
error: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
