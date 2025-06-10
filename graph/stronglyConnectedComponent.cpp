// stronglyConnectedComponent


//what does SCC means?
// Strongly Connected Component (SCC) is a subgraph where every vertex is reachable from every other vertex in that subgraph.
// E:G: In a directed graph, if there is a path from vertex A to vertex B and a path from vertex B to vertex A, then A and B are in the same SCC.

// How to find SCC?
// One of the most common algorithms to find SCCs is Kosaraju's algorithm, which involves two depth-first searches (DFS).
// The first DFS is used to determine the finishing order of vertices, and the second DFS is used to explore the transposed graph in that order.

// -------Common Doubts-------
// 1. What is the difference between SCC and connected components?
//    - SCC is for directed graphs, where every vertex can reach every other vertex in the component.
//    - Connected components are for undirected graphs, where every vertex can reach every other vertex in the component.

//2. Can a graph have multiple SCCs?
//   - Yes, a directed graph can have multiple SCCs. Each SCC is a maximal subgraph where every vertex is reachable from every other vertex in that subgraph.

//3. What is the time complexity of finding SCCs using Kosaraju's algorithm?
//   - The time complexity of Kosaraju's algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph.

//4. Can a single vertex be an SCC?
//   - Yes, a single vertex can be an SCC if it has no outgoing edges or if it is reachable from itself.

//5 . What is the significance of SCC in real-world applications?
//    - SCCs are important in various applications such as network analysis, social network analysis, and understanding the structure of directed graphs in general. They help identify clusters of strongly connected nodes, which can represent tightly-knit communities or components in a network.

/* Undirected:
A—B—C  (connected)

Directed:
A → B → C  (weakly connected)
C → A missing → not strongly connected */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;



//Lets implement Kosaraju's algorithm to find strongly connected components (SCCs) in a directed graph.
//whats is my first step?
  // 1. Perform a DFS to get the finishing order of vertices.
    //Lets create a function to perform DFS and store the finishing order in a stack.
    //in here what is finishing order?
    // Finishing order is the order in which vertices are finished during the DFS traversal.
    //E:G if we have a graph with vertices A, B, C, D, and E, and the DFS finishes in the order D, E, C, B, A, then the finishing order is {D, E, C, B, A}.
    // we will use a stack to store the finishing order of vertices.
    // use recursion to perform DFS and store the finishing order in a stack.
    //later we will use this finishing order to perform DFS on the transposed graph.

    void firstDfs(int node,vector<vector<int>>&adj,vector<bool>&visited,Stack<int>&st){
        visited[node]=true;//make the node visited
        //loop through all the neighbors of the node(eg: if node is 0, then loop through adj[0])
        for(int neighbour=0;neighbour<adj[node].size();neighbour++){
            int nextNode=adj[node][neighbour];//get the next node (e:g if node is 0, then nextNode will be adj[0][neighbour])
            //if not visited, then perform DFS on the next node
            //if visited then skip it
            if(!visited[nextNode]){
                firstDfs(nextNode,adj,visited,st);
            }
        }
        //after visiting all the neighbors, push the node to the stack
        // e:g if node is 0, then push 0 to the stack
        st.push(node);
    }







int main() {
    int V = 5;
    vector<vector<int>> adj = {
        {1},    // 0 → 1
        {2},    // 1 → 2
        {0, 3}, // 2 → 0, 3
        {4},    // 3 → 4
        {}      // 4 → no outgoing edge
    };

    vector<vector<int>> sccs = findSCCs(V, adj);

    cout << "Strongly Connected Components:" << endl;
    for (auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
