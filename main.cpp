#include "main.h"
#include <iostream>

int main() {
    Stack stack;

    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);

        std::cout << "Top 
element is: " << stack.peek() 
<< std::endl;

        std::cout << "Elements: 
";
        while 
(!stack.isEmpty()) {
            std::cout << 
stack.pop() << " ";
        }
        std::cout << std::endl;

        // Test underflow
        stack.pop();
    } catch (const 
std::exception& e) {
        std::cerr << e.what() 
<< std::endl;
    }

    return 0;
}
#include 
"main.h"
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

