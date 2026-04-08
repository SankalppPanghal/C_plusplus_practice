#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    // 1. Initialization
    std::unordered_set<std::string> vipList = {"Alice", "Bob", "Charlie"};

    // 2. Adding elements
    vipList.insert("Dave");
    
    // Trying to add a duplicate! The set will simply ignore this.
    vipList.insert("Alice"); 

    // 3. Getting current size
    // Size is 4, not 5, because the second "Alice" was rejected.
    std::cout << "Size: " << vipList.size() << "\n"; 

    // 4. Searching for an element (The primary purpose of a set)
    // Using C++20 .contains() (Use .find() == .end() for older C++)
    if (vipList.contains("Bob")) {
        std::cout << "Bob is allowed in!\n";
    }

    // 5. Iterating through the set
    for (const std::string& name : vipList) {
        std::cout << name << " "; 
    }
    // Output order will be scrambled! e.g., Dave Bob Alice Charlie

    // 6. Removing an element
    vipList.erase("Charlie"); 

    std::vector<int> messyData = {1, 2, 2, 3, 3, 3, 4};
    // Pour the vector into a set using range initialization
    std::unordered_set<int> cleanSet(messyData.begin(), messyData.end());
    // cleanSet is now just: 1, 2, 3, 4

    return 0;
}