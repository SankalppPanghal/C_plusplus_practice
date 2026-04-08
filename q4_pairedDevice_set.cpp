/* 
Problem 4: The Bluetooth Whitelist (Unordered Set)

Concepts: std::unordered_set, O(1) lookups, memory safety.

Scenario: Modern CPAP machines connect to external Bluetooth sensors (like pulse oximeters). To prevent unauthorized devices from interfering, the CPAP firmware maintains a whitelist of paired MAC addresses.

Requirements:

Implement the AccessoryManager class.

void pairDevice(const std::string& macAddress): Adds a new device to the whitelist.

bool isAuthorized(const std::string& macAddress): Returns true if the device is in the whitelist, false otherwise.

Optimization: The device might check authorization hundreds of times a second. isAuthorized must execute in O(1) average time.
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class AccessoryManager {
private:
    // TODO: Choose the right STL container for O(1) lookups
    std::unordered_set<std::string> pairedDevices;
    
public:
    void pairDevice(const std::string& macAddress) {
        // TODO: Add to your container
        pairedDevices.insert(macAddress);
    }

    bool isAuthorized(const std::string& macAddress) {
        // TODO: Check if it exists
        auto it = pairedDevices.find(macAddress);
        return it!=pairedDevices.end(); 
    }
};

int main() {
    AccessoryManager manager;
    manager.pairDevice("00:1B:44:11:3A:B7");
    manager.pairDevice("E4:AA:EA:88:22:10");

    std::cout << "Test 1 (Expected 1): " << manager.isAuthorized("00:1B:44:11:3A:B7") << std::endl;
    std::cout << "Test 2 (Expected 0): " << manager.isAuthorized("99:88:77:66:55:44") << std::endl;

    return 0;
}