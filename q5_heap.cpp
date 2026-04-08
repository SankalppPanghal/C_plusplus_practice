/*
Problem 5: The Critical Alarm Queue (Heap / Priority Queue)

Concepts: std::priority_queue, custom structs, operator overloading.

Scenario: The device generates various alarms (e.g., "Mask Leak", "Motor Overheating", "Filter Replacement"). Every alarm has a severity level (1 to 10, where 10 is the most critical). The processor must always handle the most severe alarms first, regardless of what order they arrived in.

Requirements:

Implement the AlarmSystem class.

void triggerAlarm(int severity, const std::string& message): Adds an alarm to the system.

std::string handleNextAlarm(): Removes and returns the message of the highest severity alarm. If the system is empty, return "NONE".

Optimization: Finding the highest priority item should be O(1), and insertions/removals should be O(logN).
*/

#include <iostream>
#include <queue>
#include <string>

// Hint: You might need a struct to bind severity and message together
struct Alarm {
    int severity;
    std::string message;
    
    // In C++, a priority_queue needs to know how to compare two objects.
    // You can overload the '<' operator here to teach it how to sort Alarms!
    bool operator<(const Alarm& other) const {
        return this->severity < other.severity;
    }
};

class AlarmSystem {
private:
    // TODO: Declare your priority_queue here
    std::priority_queue<Alarm> alarmq;

public:
    void triggerAlarm(int severity, const std::string& message) {
        // TODO: Implement
        struct Alarm alarm{severity,message};
        alarmq.push(alarm);

    }

    std::string handleNextAlarm() {
        // TODO: Implement. Don't forget to check if the queue is empty first!
        if (!alarmq.empty())
        {
            std::string nextAlarm = alarmq.top().message;
            alarmq.pop();
            return nextAlarm;
        }
        else
        {
            return "NONE";
        }
    }
};

int main() {
    AlarmSystem system;
    system.triggerAlarm(3, "Change Filter");
    system.triggerAlarm(10, "MOTOR FAILURE");
    system.triggerAlarm(5, "Mask Leak");

    std::cout << "Next Alarm: " << system.handleNextAlarm() << std::endl; // Expected: MOTOR FAILURE
    std::cout << "Next Alarm: " << system.handleNextAlarm() << std::endl; // Expected: Mask Leak
    std::cout << "Next Alarm: " << system.handleNextAlarm() << std::endl; // Expected: Change Filter

    return 0;
}