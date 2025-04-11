// Bag.cpp
#include "Bag.h"
#include <iostream>

// Constructor
Bag::Bag(size_t initialCapacity) : size(0), capacity(initialCapacity) {
    std::cout << "Constructor called. Allocating memory for capacity: " << capacity << std::endl;
    data = new int[capacity];
}

// Destructor
Bag::~Bag() {
    std::cout << "Destructor called. Deallocating memory at address: " << data << std::endl;
    delete[] data;
    // Setting to nullptr is not necessary since the object is being destroyed,
    // but it's a good habit for safety in other scenarios
    data = nullptr;
    size = 0;
    capacity = 0;
}

// Copy constructor
Bag::Bag(const Bag& other) : size(other.size), capacity(other.capacity) {
    std::cout << "Copy constructor called. Creating deep copy." << std::endl;
    // Allocate new memory
    data = new int[capacity];
    // Copy each element from the other bag
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Copy assignment operator
Bag& Bag::operator=(const Bag& other) {
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other) {  // Check for self-assignment
        // Deallocate old memory
        delete[] data;
        
        // Copy member variables
        size = other.size;
        capacity = other.capacity;
        
        // Allocate new memory
        data = new int[capacity];
        
        // Copy elements
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Array access operator
int& Bag::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// Const array access operator
const int& Bag::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// Addition operator
Bag Bag::operator+(const Bag& other) const {
    // Create a new bag with enough capacity for both bags
    Bag result(capacity + other.capacity);
    
    // Copy elements from this bag
    for (size_t i = 0; i < size; ++i) {
        result.add(data[i]);
    }
    
    // Copy elements from other bag
    for (size_t i = 0; i < other.size; ++i) {
        result.add(other.data[i]);
    }
    
    return result;
}

// Stream insertion operator for cout
std::ostream& operator<<(std::ostream& os, const Bag& bag) {
    os << "Bag [size=" << bag.size << ", capacity=" << bag.capacity << "]: ";
    for (size_t i = 0; i < bag.size; ++i) {
        os << bag.data[i];
        if (i < bag.size - 1) {
            os << " ";
        }
    }
    return os;
}

// Add element to the bag
void Bag::add(int value) {
    // Check if we need to resize
    if (size >= capacity) {
        resize(capacity * 2);
    }
    
    // Add the new element
    data[size++] = value;
}

// Remove first occurrence of value
void Bag::remove(int value) {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            // Shift all elements after this one left by one position
            for (size_t j = i; j < size - 1; ++j) {
                data[j] = data[j + 1];
            }
            --size;
            
            // Optionally resize if the bag is too empty
            if (size < capacity / 4 && capacity > 10) {
                resize(capacity / 2);
            }
            
            return; // Exit after removing the first occurrence
        }
    }
    // If we get here, the value wasn't found
    std::cout << "Value " << value << " not found in the bag." << std::endl;
}

// Check if value is in the bag
bool Bag::contains(int value) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

// Get current size
size_t Bag::getSize() const {
    return size;
}

// Get current capacity
size_t Bag::getCapacity() const {
    return capacity;
}

// Resize the bag
void Bag::resize(size_t newCapacity) {
    std::cout << "Resizing from " << capacity << " to " << newCapacity << std::endl;
    
    // Allocate new memory
    int* newData = new int[newCapacity];
    
    // Copy existing elements (only as many as will fit in the new array)
    size_t elementsToCopy = (size < newCapacity) ? size : newCapacity;
    for (size_t i = 0; i < elementsToCopy; ++i) {
        newData[i] = data[i];
    }
    
    // Delete old memory
    delete[] data;
    
    // Update members
    data = newData;
    capacity = newCapacity;
    
    // Update size if we had to shrink and lost elements
    if (size > capacity) {
        size = capacity;
    }
}