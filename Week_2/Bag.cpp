// Bag.cpp
#include "Bag.h"
#include <iostream>

// Constructor
Bag::Bag(size_t initialCapacity) {
    // TODO: Initialize size and capacity
    // TODO: Allocate memory for data array
}

// Destructor
Bag::~Bag() {
    // TODO: Deallocate memory for data array
}

// Copy constructor
Bag::Bag(const Bag& other) {
    // TODO: Create a deep copy of the other bag
    // Make sure to allocate new memory and copy all elements
}

// Copy assignment operator
Bag& Bag::operator=(const Bag& other) {
    // TODO: Implement copy-and-swap idiom or similar approach
    // Check for self-assignment
    // Deallocate old memory
    // Allocate new memory
    // Copy elements
    return *this;
}

// Array access operator
int& Bag::operator[](size_t index) {
    // TODO: Add bounds checking
    // Return reference to the element at index
}

// Const array access operator
const int& Bag::operator[](size_t index) const {
    // TODO: Add bounds checking
    // Return const reference to the element at index
}

// Addition operator
Bag Bag::operator+(const Bag& other) const {
    // TODO: Create a new bag that contains elements from both bags
    // Return the new bag
}

// Stream insertion operator for cout
std::ostream& operator<<(std::ostream& os, const Bag& bag) {
    // TODO: Implement custom printing format
    // For example: "Bag [size=5, capacity=10]: 1 3 5 7 9"
    return os;
}

// Add element to the bag
void Bag::add(int value) {
    // TODO: Add the value to the bag
    // If the bag is full, resize it
}

// Remove first occurrence of value
void Bag::remove(int value) {
    // TODO: Find and remove the first occurrence of value
    // Shift remaining elements to fill the gap
}

// Check if value is in the bag
bool Bag::contains(int value) const {
    // TODO: Check if the value exists in the bag
    // Return true if found, false otherwise
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
    // TODO: Implement resizing logic
    // Allocate new larger array
    // Copy existing elements
    // Delete old array
    // Update capacity
}