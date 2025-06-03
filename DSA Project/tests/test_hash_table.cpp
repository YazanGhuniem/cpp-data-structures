#include <iostream>
#include <cassert>
#include <string>
#include "hash_table_chaining.h"
#include "hash_table_open_addressing.h"

void test_hash_table_chaining() {
    std::cout << "Testing Hash Table with Chaining..." << std::endl;
    
    HashTableChaining<std::string, int> grades;
    
    // Test insertion
    grades.insert("Alice", 95);
    grades.insert("Bob", 87);
    grades.insert("Charlie", 92);
    
    assert(grades.size() == 3);
    assert(!grades.empty());
    
    // Test find
    int grade;
    assert(grades.find("Alice", grade) && grade == 95);
    assert(grades.find("Bob", grade) && grade == 87);
    assert(!grades.find("David", grade));
    
    // Test operator[]
    grades["David"] = 88;
    assert(grades.size() == 4);
    assert(grades.find("David", grade) && grade == 88);
    
    // Test update
    grades["Alice"] = 98;
    assert(grades.find("Alice", grade) && grade == 98);
    
    // Test removal
    assert(grades.remove("Bob"));
    assert(!grades.find("Bob", grade));
    assert(grades.size() == 3);
    
    grades.print_stats();
    
    std::cout << "Hash Table Chaining tests passed!" << std::endl;
}

void test_hash_table_open_addressing() {
    std::cout << "Testing Hash Table with Open Addressing..." << std::endl;
    
    HashTableOpenAddressing<int, std::string> names;
    
    // Test basic operations
    names.insert(1, "One");
    names.insert(2, "Two");
    names.insert(3, "Three");
    
    std::string value;
    assert(names.find(1, value) && value == "One");
    assert(names.find(2, value) && value == "Two");
    assert(!names.find(99, value));
    
    // Test operator[]
    names[4] = "Four";
    assert(names.find(4, value) && value == "Four");
    
    // Test removal
    assert(names.remove(2));
    assert(!names.find(2, value));
    
    names.print_stats();
    
    std::cout << "Hash Table Open Addressing tests passed!" << std::endl;
}

int main() {
    test_hash_table_chaining();
    test_hash_table_open_addressing();
    
    std::cout << "All hash table tests passed!" << std::endl;
    return 0;
} 