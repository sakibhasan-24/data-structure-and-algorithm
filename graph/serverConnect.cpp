#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class InternetNetwork {
private:
    unordered_map<string, vector<string>> serverGraph;         // Original graph
    unordered_map<string, vector<string>> reversedGraph;       // Reversed graph
    unordered_set<string> visited;                             // Visited tracking
    stack<string> finishOrder;                                 // Stack to store order of finishing times
    vector<vector<string>> stronglyConnectedComponents;        // Final SCCs

    // First DFS - to fill finishOrder stack
    void dfsOrder(const string& server) {
        visited.insert(server);
        for (const string& neighbor : serverGraph[server]) {
            if (!visited.count(neighbor)) {
                dfsOrder(neighbor);
            }
        }
        finishOrder.push(server);
    }

    // Second DFS - on reversed graph to collect SCCs
    void dfsComponent(const string& server, vector<string>& component) {
        visited.insert(server);
        component.push_back(server);
        for (const string& neighbor : reversedGraph[server]) {
            if (!visited.count(neighbor)) {
                dfsComponent(neighbor, component);
            }
        }
    }

public:
    void addDependency(const string& fromServer, const string& toServer) {
        serverGraph[fromServer].push_back(toServer);
        reversedGraph[toServer].push_back(fromServer); // Build reversed graph during input 
    }

    void findCriticalClusters() {
        // Step 1: Do DFS to compute finish order
        visited.clear();
        for (const auto& pair : serverGraph) {
            const string& server = pair.first;
            if (!visited.count(server)) {
                dfsOrder(server);
            }
        }

        // Step 2: Process nodes in reverse finish order on reversed graph
        visited.clear();
        while (!finishOrder.empty()) {
            string server = finishOrder.top();
            finishOrder.pop();
            if (!visited.count(server)) {
                vector<string> component;
                dfsComponent(server, component);
                sort(component.begin(), component.end()); // optional: sorted output
                stronglyConnectedComponents.push_back(component);
            }
        }

        // Output results
        cout << stronglyConnectedComponents.size() << endl;
        for (const auto& component : stronglyConnectedComponents) {
            for (const string& server : component) {
                cout << server << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numServers, numConnections;
    cin >> numServers >> numConnections;

    InternetNetwork network;
    for (int i = 0; i < numConnections; ++i) {
        string from, to;
        cin >> from >> to;
        network.addDependency(from, to);
    }

    network.findCriticalClusters();

    return 0;
}
