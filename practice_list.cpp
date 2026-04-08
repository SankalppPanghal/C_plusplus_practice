#include <iostream>
#include <list>

int main() {
    // 1. Initialization
    std::list<int> myList = {10, 20, 30};

    // 2. Adding to both ends (Incredibly fast)
    myList.push_back(40);  // [10, 20, 30, 40]
    myList.push_front(5);  // [5, 10, 20, 30, 40]

    // 3. Accessing elements (Only the ends are directly accessible)
    std::cout << "Front: " << myList.front() << "\n"; // Output: 5
    std::cout << "Back: " << myList.back() << "\n";   // Output: 40

    // 4. Iterating (Must use iterators or a range-based for loop)
    for (int num : myList) {
        std::cout << num << " "; 
    }

    // 5. Inserting in the middle
    // You must first get an iterator pointing to the exact spot.
    // Let's point to the second element (10)
    auto it = myList.begin();
    std::advance(it, 1); // Moves the iterator forward 1 step
    
    // Insert 99 right before the 10
    myList.insert(it, 99); // [5, 99, 10, 20, 30, 40]

    // 6. Removing elements
    myList.pop_front();    // Removes the 5
    myList.remove(30);     // Searches for and destroys all 30s!

    return 0;
}