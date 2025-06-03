#include <iostream>
#include <string>
#include "hash_table_chaining.h"
#include "hash_table_open_addressing.h"

int main() {
    std::cout << "=== Hash Table Examples ===" << std::endl;
    
    // Example 1: Student grades with chaining
    std::cout << "\n--- Student Grades (Chaining) ---" << std::endl;
    HashTableChaining<std::string, double> student_grades;
    
    student_grades.insert("Alice Johnson", 3.8);
    student_grades.insert("Bob Smith", 3.2);
    student_grades.insert("Carol Davis", 3.9);
    student_grades.insert("David Wilson", 3.5);
    
    // Look up some grades
    double gpa;
    if (student_grades.find("Alice Johnson", gpa)) {
        std::cout << "Alice's GPA: " << gpa << std::endl;
    }
    
    // Update a grade
    student_grades["Bob Smith"] = 3.4;
    std::cout << "Updated Bob's GPA to 3.4" << std::endl;
    
    student_grades.print_stats();
    
    // Example 2: Word frequency counter with open addressing
    std::cout << "\n--- Word Frequency (Open Addressing) ---" << std::endl;
    HashTableOpenAddressing<std::string, int> word_count;
    
    std::vector<std::string> words = {"hello", "world", "hello", "cpp", "world", "hello"};
    
    for (const auto& word : words) {
        word_count[word]++;  // increment count (starts at 0 if not found)
    }
    
    // Print word frequencies
    int count;
    for (const auto& word : {"hello", "world", "cpp"}) {
        if (word_count.find(word, count)) {
            std::cout << word << ": " << count << " times" << std::endl;
        }
    }
    
    word_count.print_stats();
    
    return 0;
} 