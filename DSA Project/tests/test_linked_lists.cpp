#include <iostream>
#include <cassert>
#include "singly_linked_list.h"
#include "doubly_linked_list.h"

void test_singly_linked_list() {
    std::cout << "Testing Singly Linked List..." << std::endl;
    
    SinglyLinkedList<int> list;
    
    // Test empty list
    assert(list.empty());
    assert(list.size() == 0);
    
    // Test push operations
    list.push_front(1);
    list.push_front(2);
    list.push_back(3);
    
    assert(!list.empty());
    assert(list.size() == 3);
    assert(list.front() == 2);
    
    // Test find
    assert(list.find(1));
    assert(list.find(3));
    assert(!list.find(99));
    
    // Test remove
    assert(list.remove(1));
    assert(list.size() == 2);
    assert(!list.find(1));
    
    // Test iterator
    std::cout << "Elements: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    list.clear();
    assert(list.empty());
    
    std::cout << "Singly Linked List tests passed!" << std::endl;
}

void test_doubly_linked_list() {
    std::cout << "Testing Doubly Linked List..." << std::endl;
    
    DoublyLinkedList<int> list;
    
    // Test basic operations
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    
    assert(list.size() == 3);
    assert(list.front() == 0);
    assert(list.back() == 2);
    
    // Test pop operations
    list.pop_front();
    assert(list.front() == 1);
    
    list.pop_back();
    assert(list.back() == 1);
    assert(list.size() == 1);
    
    std::cout << "Doubly Linked List tests passed!" << std::endl;
}

int main() {
    test_singly_linked_list();
    test_doubly_linked_list();
    
    std::cout << "All linked list tests passed!" << std::endl;
    return 0;
} 