void Stack::push(int value) {
    if (top >= STACK_SIZE - 1) {
        throw std::overflow_error("Stack 
overflow");
    }
    arr[++top] = value;
}

int Stack::pop() {
    if (top < 0) {
        throw std::underflow_error("Stack 
underflow");
    }
    return arr[top--];
}

int Stack::peek() {
    if (top < 0) {
        throw std::underflow_error("Stack 
underflow");
    }
    return arr[top];
}
#include "stack.h"

Stack::Stack() : top(-1) {}

void Stack::push(int value) {
    // Implementation goes here
}

int Stack::pop() {
    // Implementation goes here
    return 0;
}

int Stack::peek() {
    // Implementation goes here
    return 0;
}

bool Stack::isEmpty() {
    return top == -1;
}

