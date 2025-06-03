#include <iostream>
#include <string>
#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "stack.h"
#include "queue.h"

int main() {
    std::cout << "=== My Data Structures Library Demo ===" << std::endl;
    
    // Demonstrate singly linked list
    std::cout << "\n--- Singly Linked List ---" << std::endl;
    SinglyLinkedList<std::string> names;
    names.push_back("Alice");
    names.push_back("Bob");
    names.push_front("Charlie");
    
    std::cout << "Names in list: ";
    for (auto it = names.begin(); it != names.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Demonstrate stack
    std::cout << "\n--- Stack ---" << std::endl;
    Stack<int> numbers;
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    
    std::cout << "Popping from stack: ";
    while (!numbers.empty()) {
        std::cout << numbers.top() << " ";
        numbers.pop();
    }
    std::cout << std::endl;
    
    // Demonstrate queue
    std::cout << "\n--- Queue ---" << std::endl;
    Queue<char> letters;
    letters.enqueue('A');
    letters.enqueue('B');
    letters.enqueue('C');
    
    std::cout << "Dequeuing from queue: ";
    while (!letters.empty()) {
        std::cout << letters.front() << " ";
        letters.dequeue();
    }
    std::cout << std::endl;
    
    return 0;
} 