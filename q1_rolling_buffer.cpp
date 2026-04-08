/*
Problem 1: The Rolling Average Buffer

Scenario: A pressure sensor sends a continuous stream of integer readings. To smooth out noisy data, the device needs to maintain a rolling average of the last K readings. You need to implement a class that efficiently handles this continuous stream.

Requirements:

Implement the PressureMonitor class.

PressureMonitor(int k) Initializes the object with the size of the window K.

double next(int val) Adds the new reading val to the stream and returns the exact average of the last K readings. If there are fewer than K readings, return the average of all readings so far.

Optimization: Both adding a reading and calculating the average must happen in O(1) time. (Hint: Don't loop through the elements every time you calculate the average).
*/

#include <iostream>
#include <queue>

class PressureMonitor {
private:
    // TODO: Add your private member variables here
    std::queue<int> q;
    int K;
    long long sum; // Prevent overflow with 64bit value

public:
    PressureMonitor(int k) :  K(k), sum(0) 
    {
        // TODO: Initialize your variables
    }
    
    double next(int val) {
        // TODO: Implement the logic
        q.push(val);
        sum += val;
        if (q.size()>K)
        {
            q.pop();
            sum -= q.front();
        }
        return static_cast<double>sum/q.size(); //// Note: static_cast is the safer, modern C++ way over C-style (double) casting
    }
};

int main() {
    // Test Case
    PressureMonitor monitor(3); // Window size of 3
    
    std::cout << monitor.next(1) << std::endl;  // Expected: 1.0
    std::cout << monitor.next(10) << std::endl; // Expected: 5.5  ((1+10)/2)
    std::cout << monitor.next(3) << std::endl;  // Expected: 4.666... ((1+10+3)/3)
    std::cout << monitor.next(5) << std::endl;  // Expected: 6.0  ((10+3+5)/3)
    
    return 0;
}
