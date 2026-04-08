#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {10, 20, 30, 20, 50};

    // 1. Counting how many times '20' appears
    int count = std::count(v.begin(), v.end(), 20); // Result: 2

    // 2. Reversing the order of the vector
    std::reverse(v.begin(), v.end()); // [50, 20, 30, 20, 10]

    for(int i: v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 3. Searching a vector (since vector doesn't have a built-in .find())
    auto it = std::find(v.begin(), v.end(), 30);
    if (it != v.end()) {
        std::cout << "Found 30!\n";
    }
}