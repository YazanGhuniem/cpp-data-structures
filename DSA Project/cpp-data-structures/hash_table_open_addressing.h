#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

#include <vector>
#include <functional>
#include <iostream>

template<typename K, typename V>
class HashTableOpenAddressing {
private:
    enum EntryState { EMPTY, OCCUPIED, DELETED };
    
    struct Entry {
        K key;
        V value;
        EntryState state;
        
        Entry() : state(EMPTY) {}
        Entry(const K& k, const V& v) : key(k), value(v), state(OCCUPIED) {}
    };
    
    std::vector<Entry> table;
    size_t table_size;
    size_t num_elements;
    size_t num_deleted;  // keep track of deleted entries for load factor
    
    // Hash function
    size_t hash(const K& key) const {
        std::hash<K> hasher;
        return hasher(key) % table_size;
    }
    
    // Linear probing to find next available slot
    size_t probe(size_t start_index) const {
        size_t index = start_index;
        while (table[index].state == OCCUPIED) {
            index = (index + 1) % table_size;
            if (index == start_index) {
                // Table is full - this shouldn't happen with proper resizing
                throw std::runtime_error("Hash table is full");
            }
        }
        return index;
    }
    
    // Find index of key, or return table_size if not found
    size_t find_index(const K& key) const {
        size_t start_index = hash(key);
        size_t index = start_index;
        
        do {
            if (table[index].state == EMPTY) {
                return table_size;  // not found
            }
            if (table[index].state == OCCUPIED && table[index].key == key) {
                return index;  // found
            }
            index = (index + 1) % table_size;
        } while (index != start_index);
        
        return table_size;  // not found
    }
    
    // Resize when load factor gets too high
    static constexpr double MAX_LOAD_FACTOR = 0.7;
    void resize_if_needed();
    void rehash(size_t new_size);
    
public:
    HashTableOpenAddressing(size_t initial_size = 16);
    ~HashTableOpenAddressing() = default;
    
    // Basic operations
    void insert(const K& key, const V& value);
    bool remove(const K& key);
    bool find(const K& key, V& value) const;
    V& operator[](const K& key);  // insert if not found
    
    // Utility
    size_t size() const;
    bool empty() const;
    double load_factor() const;
    void clear();
    void print_stats() const;
};

#include "hash_table_open_addressing.cpp"

#endif 