/*
Problem 9: Redundant Sensor Stream (Single Number)
Concepts: Bit Manipulation, Vector Iteration.

Scenario: A diagnostic bus receives ping responses from various components. For safety redundancy, every component is programmed to send its ID exactly twice during a diagnostic cycle. However, a localized interference caused exactly one component to drop its second ping.

You are given a vector of these integer IDs. Every ID appears twice, except for one that appears exactly once.

Requirements:

Write a function findMissingPair(const std::vector<int>& ids).

It must return the integer ID of the component that only pinged once.

Optimization: You must solve this in O(N) time complexity and O(1) auxiliary space. (This means you cannot use a std::unordered_set or std::unordered_map to count occurrences, as that would take O(N) memory).
*/

#include <iostream>
#include <vector>

int findMissingPair(const std::vector<int>& ids) {
    // TODO: Implement your solution here
    int temp = 0;
    for (int i: ids)
        temp = temp^i;
    return temp;
}

int main() {
    // Test Case 1
    std::vector<int> stream1 = {4, 1, 2, 1, 2};
    std::cout << "Test 1 (Expected 4): " << findMissingPair(stream1) << std::endl;

    // Test Case 2
    std::vector<int> stream2 = {14, 22, 14, 8, 22, 9, 8};
    std::cout << "Test 2 (Expected 9): " << findMissingPair(stream2) << std::endl;

    // Test Case 3
    std::vector<int> stream3 = {55};
    std::cout << "Test 3 (Expected 55): " << findMissingPair(stream3) << std::endl;

    return 0;
}