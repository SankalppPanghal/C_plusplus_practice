/*
Problem 6: Time-Series Firmware Log (Binary Search)

Concepts: std::vector, Binary Search, O(logN) time complexity.

Scenario: A technician pulls a massive log of pressure readings to diagnose a patient's sleep apnea event. The log is a strictly chronologically sorted vector of timestamps (integers representing seconds since boot). The technician wants to know if an event occurred at a specific exact timestamp.

Requirements:

Write a function bool hasReadingAtTime(const std::vector<int>& timestamps, int targetTime).

It should return true if targetTime exists in the vector, false otherwise.

Optimization: Because the log could contain millions of entries and is already sorted, you cannot use a linear for loop. You must implement a binary search algorithm (O(logN) time).
*/

#include <iostream>
#include <vector>

bool hasReadingAtTime(const std::vector<int>& timestamps, int targetTime) {
    
    int l = 0;
    int r = timestamps.size()-1;
    int m;
    while(l<=r)
    {
        m = (l+r)/2;

        if(timestamps[m] == targetTime)
            return true;
        else if (timestamps[m] > targetTime)
        {
            r = m-1;
        }
        else
        {
            l = m+1;
        }
    }

    return false;
}

int main() {
    // A sorted log of timestamps
    std::vector<int> logs = {100, 205, 310, 415, 520, 625, 730, 835};

    std::cout << "Found 415? (Expected 1): " << hasReadingAtTime(logs, 415) << std::endl;
    std::cout << "Found 500? (Expected 0): " << hasReadingAtTime(logs, 500) << std::endl;
    std::cout << "Found 835? (Expected 1): " << hasReadingAtTime(logs, 835) << std::endl;

    return 0;
}