/*

Problem 11: The Hardware State Machine
Scenario: You are writing the firmware for the main blower motor of a ventilator. The motor has strict safety transitions based on hardware events.

States: OFF, STARTING, RUNNING, ERROR.

Events: BUTTON_PRESS, TARGET_RPM_REACHED, OBSTRUCTION_DETECTED, RESET.

Transition Rules:

Default starting state is OFF.

OFF + BUTTON_PRESS ➔ STARTING.

STARTING + TARGET_RPM_REACHED ➔ RUNNING.

RUNNING + BUTTON_PRESS ➔ OFF.

If OBSTRUCTION_DETECTED happens while STARTING or RUNNING, immediately ➔ ERROR.

Once in ERROR, the only event that does anything is RESET ➔ OFF.

Any other combination of State + Event does nothing (the state remains unchanged).

Requirements:

Implement the void processEvent(Event e) method inside the MotorController class.

Update currentState based on the transition rules.

*/

#include <iostream>
#include <string>

enum class State {
    OFF,
    STARTING,
    RUNNING,
    ERROR
};

enum class Event {
    BUTTON_PRESS,
    TARGET_RPM_REACHED,
    OBSTRUCTION_DETECTED,
    RESET
};

class MotorController {
private:
    State currentState;

public:
    MotorController() : currentState(State::OFF) {}

    void processEvent(Event e) {
        // TODO: Implement the state machine rules
        switch (currentState)
        {
        case State::OFF:
            if (e == Event::BUTTON_PRESS)
                currentState = State::STARTING;
            break;
        case State::STARTING:
            if (e == Event::TARGET_RPM_REACHED)
                currentState = State::RUNNING;
            else if(e == Event::OBSTRUCTION_DETECTED)
                currentState = State::ERROR;
            break;
        case State::RUNNING:
            if (e == Event::BUTTON_PRESS)
                currentState = State::OFF;
            else if(e == Event::OBSTRUCTION_DETECTED)
                currentState = State::ERROR;
            break;
        case State::ERROR:
            if (e == Event::RESET)
                currentState = State::OFF;
            break;
        default:
            break;
        }
        
    }

    State getCurrentState() const {
        return currentState;
    }
};

// --- Helper to print states ---
std::string stateToString(State s) {
    switch(s) {
        case State::OFF: return "OFF";
        case State::STARTING: return "STARTING";
        case State::RUNNING: return "RUNNING";
        case State::ERROR: return "ERROR";
    }
    return "UNKNOWN";
}

int main() {
    MotorController motor;
    
    // Sequence 1: Normal Start and Stop
    motor.processEvent(Event::BUTTON_PRESS);
    std::cout << "After Button Press: " << stateToString(motor.getCurrentState()) << " (Expected: STARTING)\n";
    
    motor.processEvent(Event::TARGET_RPM_REACHED);
    std::cout << "After RPM Reached: " << stateToString(motor.getCurrentState()) << " (Expected: RUNNING)\n";

    motor.processEvent(Event::BUTTON_PRESS);
    std::cout << "After Button Press: " << stateToString(motor.getCurrentState()) << " (Expected: OFF)\n";

    // Sequence 2: Obstruction and Reset
    motor.processEvent(Event::BUTTON_PRESS); // To STARTING
    motor.processEvent(Event::OBSTRUCTION_DETECTED);
    std::cout << "After Obstruction: " << stateToString(motor.getCurrentState()) << " (Expected: ERROR)\n";

    motor.processEvent(Event::BUTTON_PRESS); // Should do nothing
    std::cout << "After Button Press (in Error): " << stateToString(motor.getCurrentState()) << " (Expected: ERROR)\n";

    motor.processEvent(Event::RESET);
    std::cout << "After Reset: " << stateToString(motor.getCurrentState()) << " (Expected: OFF)\n";

    return 0;
}