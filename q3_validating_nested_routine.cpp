/*
Problem 3: Validating Nested Diagnostic Routines

Concepts: std::stack, std::string.

Scenario: The device receives a string of control characters representing nested diagnostic routines.

( starts a minor test, ) ends it.

[ starts a major test, ] ends it.

{ starts a calibration, } ends it.

A sequence is considered valid only if every routine is closed by the correct character in the exact reverse order it was opened. (This is a classic algorithmic problem, but highly relevant for parsing nested protocols).

Requirements:

Write a function isValidSequence(const std::string& sequence).

Return true if the string is valid, false otherwise.

*/

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

bool isValidSequence(const std::string& sequence) {
    // TODO: Use a stack to track open routines. 
    // If you see a closing bracket, check the top of the stack.
    std::unordered_map<char,char> closing_brace = {{'(',')'},{'{','}'},{'[',']'}};
    std::stack<char> stack;
    for(const char& c: sequence)
    {
        if (c==0) break;
        
        if (closing_brace.find(c)!=closing_brace.end())
        {
            stack.push(closing_brace[c]);
        }
        else
        {
            if (stack.empty() || c != stack.top())
                return false;
            stack.pop();
        }
    }
    return stack.empty();
}


bool isValidSequence2(const std::string& sequence) {
    std::stack<char> stack;
    
    // Pass by value for primitive types (char)
    for(char c : sequence) {
        // Zero-heap, lightning fast switch statement
        switch(c) {
            case '(': stack.push(')'); break;
            case '{': stack.push('}'); break;
            case '[': stack.push(']'); break;
            default:
                // If it's a closing bracket, check the stack
                if (stack.empty() || c != stack.top()) {
                    return false;
                }
                stack.pop();
        }
    }
    
    // If stack is empty, every routine was closed perfectly
    return stack.empty(); 
} 

int main() {
    std::string test1 = "()[]{}";
    std::string test2 = "([)]";
    std::string test3 = "{[()]}";
    
    std::cout << "Test 1 (Expected 1/true): " << isValidSequence2(test1) << std::endl;
    std::cout << "Test 2 (Expected 0/false): " << isValidSequence2(test2) << std::endl;
    std::cout << "Test 3 (Expected 1/true): " << isValidSequence2(test3) << std::endl;
    
    return 0;
}