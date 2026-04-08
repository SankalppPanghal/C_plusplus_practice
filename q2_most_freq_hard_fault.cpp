/*
Problem 2: Most Frequent Hardware Fault

Scenario: During a diagnostic run, the device firmware logs error codes into a vector. You need to write an analysis function that parses this log and identifies the error code that occurred most frequently.

Requirements:

Write a function findMostFrequentError(const std::vector<std::string>& errors).

It should return the std::string of the most frequent error.

If there is a tie, you can return any of the tied error codes.

Optimization: Achieve this in O(N) time complexity.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string findMostFrequentError(const std::vector<std::string>& errors) {
    // TODO: Implement using an unordered_map to count frequencies
    std::unordered_map<std::string, int> count;
    int highest_count = 0;
    std::string ans = "";

    for(const std::string& error : errors) //Use & to avoid copy
    {
        count[error] += 1;
        if (count[error] > highest_count)
        {
            ans = error;
            highest_count = count[error];
        }
    }
    return ans;
}

int main() {
    std::vector<std::string> log = {
        "ERR_TEMP", "ERR_VOLTAGE", "ERR_TEMP", 
        "ERR_MOTOR", "ERR_VOLTAGE", "ERR_TEMP"
    };
    
    std::string result = findMostFrequentError(log);
    std::cout << "Most frequent error: " << result << std::endl; 
    // Expected: ERR_TEMP
    
    return 0;
}