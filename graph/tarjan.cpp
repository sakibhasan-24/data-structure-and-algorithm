#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int u, vector<int> adj[], vector<int>& disc, vector<int>& low,
         stack<int>& s, vector<bool>& inStack, int& time,
         vector<vector<int>>& result) {
    disc[u] = low[u] = time++;
    s.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            // If not visited, explore
            dfs(v, adj, disc, low, s, inStack, time, result);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v]) {
            // Back edge to a node still in stack
            low[u] = min(low[u], disc[v]);
        }
    }

    // If node is the head of an SCC
    if (low[u] == disc[u]) {
        vector<int> scc;
        while (true) {
            int node = s.top(); s.pop();
            inStack[node] = false;
            scc.push_back(node);
            if (node == u) break;
        }
        result.push_back(scc);
    }
}

vector<vector<int>> tarjansSCC(int V, vector<int> adj[]) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> s;
    vector<vector<int>> result;
    int time = 0;
    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            dfs(i, adj, disc, low, s, inStack, time, result);
        }
    }
    return result;
}
