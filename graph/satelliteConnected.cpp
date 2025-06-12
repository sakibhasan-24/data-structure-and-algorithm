#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

// Global variables for graph, reversed graph, visited map, and stack for order
unordered_map<string, vector<string>> graph;
unordered_map<string, vector<string>> reversedGraph;
unordered_map<string, bool> visited;
stack<string> order;

// DFS on original graph to fill stack according to finishing times
void dfs1(const string& node) {
    visited[node] = true;
    for (const auto& neigh : graph[node]) {
        if (!visited[neigh]) {
            dfs1(neigh);
        }
    }
    order.push(node);  // push node after visiting all neighbors
}

// DFS on reversed graph to get strongly connected components
void dfs2(const string& node, vector<string>& component) {
    visited[node] = true;
    component.push_back(node);
    for (const auto& neigh : reversedGraph[node]) {
        if (!visited[neigh]) {
            dfs2(neigh, component);
        }
    }
}

// Kosaraju's algorithm main function
vector<vector<string>> findSCC(const vector<pair<string, string>>& edges) {
    unordered_set<string> nodes;

    // Build graph and reversedGraph, collect all nodes and initialize visited
    for (auto& e : edges) {
        graph[e.first].push_back(e.second);
        reversedGraph[e.second].push_back(e.first);
        nodes.insert(e.first);
        nodes.insert(e.second);
        visited[e.first] = false;
        visited[e.second] = false;
    }

    // Step 1: DFS on original graph to get nodes in order stack
    for (const auto& node : nodes) {
        if (!visited[node]) {
            dfs1(node);
        }
    }

    // Reset visited for second DFS
    for (auto& [node, _] : visited) {
        visited[node] = false;
    }

    vector<vector<string>> sccs;

    // Step 2: DFS on reversed graph in order of decreasing finishing time
    while (!order.empty()) {
        string node = order.top();
        order.pop();

        if (!visited[node]) {
            vector<string> component;
            dfs2(node, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}

int main() {
    vector<pair<string, string>> edges = {
        {"A", "B"}, {"B", "C"}, {"C", "A"},
        {"B", "D"}, {"D", "E"}, {"E", "F"}, {"F", "D"},
        {"G", "F"}, {"G", "H"}, {"H", "I"}, {"I", "J"}, {"J", "G"}
    };

    vector<vector<string>> sccs = findSCC(edges);

    cout << "Strongly Connected Components:\n";
    for (const auto& component : sccs) {
        for (const auto& node : component) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
