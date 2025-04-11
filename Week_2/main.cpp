// main.cpp
#include "Bag.h"
#include <iostream>

// Function to test the Big Three
void testBigThree() {
    std::cout << "\n=== Testing Big Three ===\n";
    
    // Create a bag and add some data
    Bag bag1(5);
    for (int i = 0; i < 7; ++i) {
        bag1.add(i * 10);
    }
    std::cout << "bag1: " << bag1 << std::endl;
    
    // Test copy constructor
    Bag bag2 = bag1;  // Uses copy constructor
    std::cout << "bag2 (copied from bag1): " << bag2 << std::endl;
    
    // Modify bag2 and show it doesn't affect bag1 (proving deep copy)
    bag2[0] = 999;
    std::cout << "After modifying bag2[0]:\n";
    std::cout << "bag1: " << bag1 << std::endl;
    std::cout << "bag2: " << bag2 << std::endl;
    
    // Test copy assignment operator
    Bag bag3;
    std::cout << "bag3 (before assignment): " << bag3 << std::endl;
    bag3 = bag1;  // Uses copy assignment operator
    std::cout << "bag3 (after assignment): " << bag3 << std::endl;
    
    // Test addition operator
    Bag bag4 = bag1 + bag2;
    std::cout << "bag4 (bag1 + bag2): " << bag4 << std::endl;
}

// Function to demonstrate memory issues when Big Three aren't implemented correctly
void demonstrateMemoryIssues() {
    std::cout << "\n=== Memory Management Demonstration ===\n";
    
    // Create a bag with dynamic memory
    Bag* bag1 = new Bag(5);
    for (int i = 0; i < 3; ++i) {
        bag1->add(i * 10);
    }
    std::cout << "bag1: " << *bag1 << std::endl;
    
    // Delete the bag - should call destructor and free memory properly
    delete bag1;
    std::cout << "bag1 deleted - destructor should have been called" << std::endl;
    
    // If destructor was not properly implemented, the above would cause a memory leak
    
    // Next we'll demonstrate proper scope-based destruction
    {
        std::cout << "Entering new scope..." << std::endl;
        Bag scopedBag;
        scopedBag.add(100);
        scopedBag.add(200);
        std::cout << "scopedBag: " << scopedBag << std::endl;
        std::cout << "Leaving scope..." << std::endl;
    } // scopedBag's destructor is automatically called here
    std::cout << "Scope exited - destructor should have been called" << std::endl;
}

int main() {
    std::cout << "=== Bag ADT Implementation Test ===\n";
    
    Bag bag;
    
    // Test adding elements and automatic resizing
    std::cout << "\n=== Adding Elements ===\n";
    for (int i = 0; i < 15; ++i) {
        bag.add(i * 10);
        std::cout << "After adding " << i * 10 << ": " << bag << std::endl;
    }
    
    // Test contains function
    std::cout << "\n=== Testing Contains ===\n";
    std::cout << "bag.contains(30): " << (bag.contains(30) ? "true" : "false") << std::endl;
    std::cout << "bag.contains(45): " << (bag.contains(45) ? "true" : "false") << std::endl;
    
    // Test removing elements
    std::cout << "\n=== Removing Elements ===\n";
    bag.remove(30);
    std::cout << "After removing 30: " << bag << std::endl;
    bag.remove(70);
    std::cout << "After removing 70: " << bag << std::endl;
    bag.remove(999);  // Non-existent element
    std::cout << "After trying to remove 999: " << bag << std::endl;
    
    // Test Big Three (destructor, copy constructor, copy assignment)
    testBigThree();
    
    // Demonstrate memory management
    demonstrateMemoryIssues();
    
    std::cout << "\n=== End of Test ===\n";
    
    // All automatic variables are destroyed here, should see destructor messages
    return 0;
}