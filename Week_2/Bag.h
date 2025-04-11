// Bag.h
#ifndef BAG_H
#define BAG_H

#include <iostream>

class Bag {
private:
    int* data;         // Pointer to the dynamic array
    size_t size;       // Number of elements currently in the bag
    size_t capacity;   // Total capacity of the bag

public:
    // Constructor
    Bag(size_t initialCapacity = 10);
    
    // Big Three
    ~Bag();                        // Destructor
    Bag(const Bag& other);         // Copy constructor
    Bag& operator=(const Bag& other); // Copy assignment operator
    
    // Operator overloading
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    Bag operator+(const Bag& other) const;
    
    // Stream insertion operator (for cout)
    friend std::ostream& operator<<(std::ostream& os, const Bag& bag);
    
    // Member functions
    void add(int value);         // Add element to the bag
    void remove(int value);      // Remove first occurrence of value
    bool contains(int value) const;  // Check if value is in the bag
    size_t getSize() const;      // Get current size
    size_t getCapacity() const;  // Get current capacity
    
private:
    void resize(size_t newCapacity);  // Resize the bag
};

#endif