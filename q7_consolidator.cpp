/*
Problem 7: Apnea Event Consolidator
Scenario: A CPAP machine logs "apnea events" (periods where the patient's breathing drops) as a pair of timestamps [start_time, end_time]. Because the device has multiple redundant sensors (acoustic, pressure, motor RPM), a single real-world event often triggers multiple overlapping log entries.

Before uploading the nightly summary to the doctor's cloud dashboard, the firmware needs to clean this data by consolidating any overlapping logs into single, continuous blocks of time.

Requirements:

Write a function consolidateEvents(std::vector<std::vector<int>>& events).

An event is represented as a vector of two integers: [start, end].

If two events overlap or touch (e.g., [1, 3] and [2, 5]), they should be merged into [1, 5].

Note: The input vector is not guaranteed to be in chronological order.

Return a new vector containing the consolidated events.
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> consolidateEvents(std::vector<std::vector<int>>& events) {
    // TODO: Implement your solution here

    if (events.size() <= 1)
        return events; //The C++ compiler is smart enough to see the function return type and automatically invoke the copy constructor for you.
    
    std::vector<std::vector<int>> ans;
    ans.reserve(events.size()); // Prevent Memory Fragmentation by ensuring enough size allocation on heap.

    std::vector<int> prev;

    std::sort(events.begin(), events.end(), [](const std::vector<int>&va,const std::vector<int>&vb){return va[0]<vb[0];});

    prev = events[0];

    // for(auto it = events.begin()+1 ; it!=events.end() ; it++)
    for (size_t i = 1; i<events.size(); i++)
    {
        //const auto& current = *it; | 
        const auto& current = events[i];
        
        // Overlap ; Merge
        if (current[0] <= prev[1])
        {
            prev[1] = std::max(current[1], prev[1]);
        }
        else
        {
            ans.push_back(prev);
            prev = current;
        }
        
    }
    ans.push_back(prev);

    return ans;
}

// --- Helper function to print the output ---
void printEvents(const std::vector<std::vector<int>>& events) {
    std::cout << "[";
    for (size_t i = 0; i < events.size(); ++i) {
        std::cout << "[" << events[i][0] << ", " << events[i][1] << "]";
        if (i != events.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    // Test Case 1
    std::vector<std::vector<int>> logs1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::cout << "Test 1:" << std::endl;
    std::cout << "Expected: [[1, 6], [8, 10], [15, 18]]" << std::endl;
    std::cout << "Actual:   ";
    printEvents(consolidateEvents(logs1));
    std::cout << std::endl;

    // Test Case 2: Out of order overlapping
    std::vector<std::vector<int>> logs2 = {{1, 4}, {0, 2}, {3, 5}};
    std::cout << "Test 2:" << std::endl;
    std::cout << "Expected: [[0, 5]]" << std::endl;
    std::cout << "Actual:   ";
    printEvents(consolidateEvents(logs2));
    std::cout << std::endl;

    // Test Case 3: Fully engulfed event
    std::vector<std::vector<int>> logs3 = {{1, 10}, {4, 7}};
    std::cout << "Test 3:" << std::endl;
    std::cout << "Expected: [[1, 10]]" << std::endl;
    std::cout << "Actual:   ";
    printEvents(consolidateEvents(logs3));
    std::cout << std::endl;

    return 0;
}

/*
Initial Successful Solution Attempt

std::vector<std::vector<int>> consolidateEvents(std::vector<std::vector<int>>& events) {
    // TODO: Implement your solution here

    if (events.size() <= 1)
        return std::vector<std::vector<int>>(events);
    
    std::vector<std::vector<int>> ans;
    std::vector<int> current;
    std::vector<int> prev;

    std::sort(events.begin(), events.end(), [](const std::vector<int>&va,const std::vector<int>&vb)
{
     if(va[0]==vb[0])
     {
        return va[1]<vb[1];
     }
     return va[0]<vb[0];
});

    prev = events[0];

    for(auto it = events.begin()+1 ; it!=events.end() ; it++)
    {
        current = *it;
        // Overlap ; Merge
        if (current[0] <= prev[1])
        {
            prev[0] = std::min(current[0], prev[0]);
            prev[1] = std::max(current[1], prev[1]);
        }
        else
        {
            ans.push_back(prev);
            prev = current;
        }
        
    }
    ans.push_back(prev);

    return ans;
}
*/