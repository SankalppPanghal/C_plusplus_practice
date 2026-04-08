#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <string>

// Our custom object
struct Player {
    std::string name;
    int score;
    int level;
};

int main() {
    // --- SCENARIO 1: Basic Sorting ---
    std::vector<int> nums = {50, 10, 30, 20, 40};

    // Default sort is Ascending (Smallest to Largest)
    // You provide the starting iterator and the ending iterator
    std::sort(nums.begin(), nums.end()); 
    // nums is now: [10, 20, 30, 40, 50]

    // Sort Descending (Largest to Smallest) using a built-in comparator
    std::sort(nums.begin(), nums.begin()+2, [](const int& a,const int& b){return a>b});
    // nums is now: [50, 40, 30, 20, 10]


    // --- SCENARIO 2: Sorting Custom Objects ---
    std::vector<Player> roster = {
        {"Alice", 1500, 10},
        {"Bob", 2200, 8},
        {"Charlie", 1500, 12}
    };

    // Let's sort them by Score (Highest to Lowest).
    // We use a lambda function as our custom comparator.
    std::sort(roster.begin(), roster.end(), [](const Player& a, const Player& b) {
        return a.score > b.score; 
    });
    // Order: Bob (2200), Alice (1500), Charlie (1500)

    // --- SCENARIO 3: Tie-Breaking (Advanced Sorting) ---
    // What if we want to sort by Score (Descending), 
    // but if scores are tied, sort by Level (Ascending)?
    std::sort(roster.begin(), roster.end(), [](const Player& a, const Player& b) {
        if (a.score == b.score) {
            return a.level < b.level; // Tie-breaker: Lower level goes first
        }
        return a.score > b.score;     // Main rule: Higher score goes first
    });
    // Order: Bob (2200, Lvl 8), Alice (1500, Lvl 10), Charlie (1500, Lvl 12)

    return 0;
}