#include <iostream>
#include <utility>
#include <string>

int main() {
    // 1. Initialization (Modern C++ using curly braces)
    std::pair<std::string, int> player = {"Alice", 1500};

    // 2. Initialization (Older C++ using make_pair)
    // auto figures out the types for you!
    auto enemy = std::make_pair("Goblin", 50); 

    // 3. Accessing elements
    std::cout << player.first << " has score: " << player.second << "\n";
    // Output: Alice has score: 1500

    // 4. Modifying elements
    player.second += 100; // Alice's score is now 1600

    return 0;
}