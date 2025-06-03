#include <iostream>
#include <cassert>
#include "stack.h"
#include "queue.h"

void test_stack() {
    std::cout << "Testing Stack..." << std::endl;
    
    Stack<int> stack;
    
    // Test empty stack
    assert(stack.empty());
    assert(stack.size() == 0);
    
    // Test push and top
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    assert(!stack.empty());
    assert(stack.size() == 3);
    assert(stack.top() == 30);
    
    // Test pop
    stack.pop();
    assert(stack.top() == 20);
    assert(stack.size() == 2);
    
    // Test LIFO behavior
    stack.pop();
    stack.pop();
    assert(stack.empty());
    
    std::cout << "Stack tests passed!" << std::endl;
}

void test_queue() {
    std::cout << "Testing Queue..." << std::endl;
    
    Queue<std::string> queue;
    
    // Test empty queue
    assert(queue.empty());
    assert(queue.size() == 0);
    
    // Test enqueue
    queue.enqueue("first");
    queue.enqueue("second");
    queue.enqueue("third");
    
    assert(!queue.empty());
    assert(queue.size() == 3);
    assert(queue.front() == "first");
    assert(queue.back() == "third");
    
    // Test FIFO behavior
    queue.dequeue();
    assert(queue.front() == "second");
    assert(queue.size() == 2);
    
    queue.dequeue();
    queue.dequeue();
    assert(queue.empty());
    
    std::cout << "Queue tests passed!" << std::endl;
}

int main() {
    test_stack();
    test_queue();
    
    std::cout << "All stack and queue tests passed!" << std::endl;
    return 0;
} 