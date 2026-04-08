/*
Problem 8: Sensor Mesh Network (Shortest Path)

Scenario: A ResMed CPAP machine acts as the main communication hub (Node 0) in a Bluetooth Low-Energy (BLE) mesh network. Various other sensors in the bedroom connect to each other to relay data back to the hub.

You are given the network topology as an adjacency list. You need to write a function that calculates the minimum number of "hops" (connections) a specific sensor's data must make to reach the main hub.

Requirements:
Implement the getMinimumHops(const std::vector<std::vector<int>>& network, int targetSensor) function.network[i] contains a list of all nodes that node i is directly connected to.The Hub is always node 0.Return the minimum number of hops from targetSensor to 0.If the sensor is completely disconnected and cannot reach the hub, return -1.Optimization: You must solve this in $O(V + E)$ time (Vertices + Edges) without getting stuck in infinite loops if the network has a cycle (e.g., Node 1 connects to 2, 2 connects to 1).
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

int getMinimumHops(const std::vector<std::vector<int>>& network, int targetSensor) {
    // TODO: Implement your routing algorithm here.
    
    int minimum_dist = -1;
    int hop = 0;
    int node_no;
    std::unordered_set<int> seen;
    std::queue<std::pair<int,int>> q; // Use std::pair instead std::vector to avoid heap allocation
    std::pair<int,int>temp = {targetSensor,hop};  
    q.push(temp);
    
    seen.insert(targetSensor);
    while(!q.empty())
    {
        temp = q.front();
        hop = temp.second;
        node_no = temp.first;

        // Base node found
        if(node_no == 0) 
        {
            return hop;
        }
        
        q.pop();
        

        for(int peer_no : network[node_no])
        {
            if (seen.find(peer_no)==seen.end())
            {
                seen.insert(peer_no);
                q.push({peer_no,hop+1});
            }
        }
        

    }

    return -1;
}

// --- Helper code to test your logic locally ---
int main() {
    /* Visualizing the Mesh Network:
       (Hub) 0 -- 1 -- 3 
             |         |
             2 -- 4 -- 5 -- 6
    */
    std::vector<std::vector<int>> mesh = {
        {1, 2},    // Node 0 (Hub)
        {0, 3},    // Node 1
        {0, 4},    // Node 2
        {1, 5},    // Node 3
        {2, 5},    // Node 4
        {3, 4, 6}, // Node 5
        {5}        // Node 6
    };

    std::cout << "Hops from Sensor 1 (Expected 1): " << getMinimumHops(mesh, 1) << std::endl;
    std::cout << "Hops from Sensor 5 (Expected 3): " << getMinimumHops(mesh, 5) << std::endl;
    std::cout << "Hops from Sensor 6 (Expected 4): " << getMinimumHops(mesh, 6) << std::endl;

    // Test Case: A broken/disconnected network
    std::vector<std::vector<int>> brokenMesh = {
        {1},       // Node 0 (Hub)
        {0},       // Node 1
        {3},       // Node 2 (Disconnected from Hub!)
        {2}        // Node 3
    };
    
    std::cout << "Hops from Sensor 3 (Expected -1): " << getMinimumHops(brokenMesh, 3) << std::endl;

    return 0;
}