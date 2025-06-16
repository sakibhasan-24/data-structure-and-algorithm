// what  is Bellman Ford 
    
#include<iostream>
#include<vector>
#include<queue>


using namespace std;


void bellmanFord(int V,vector<vector<int>>&edges,int src){
    vector<int>distance(V,INT_MAX);
    distance[src]=0;
    cout << "Initial distances:\n";
    for (int i = 0; i < V; i++) {
        cout << "dist[" << i << "] = " << distance[i] << endl;
    }
    cout << "-----------------------------\n";

    for(int i=0;i<V-1;i++){
        bool track=false;
        for(int j=0;j<edges.size();j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
            if(distance[v]>distance[u]+w){
                distance[v]=distance[u]+w;
                cout << "Updated dist[" << v << "] = " << distance[v] << " via node " << u << "\n";
                track=true;
            }
        }
        if (!track) {
        cout << "No update in iteration " << i+ 1 << ", stopping early.\n";
        break;
    }
    }
    // Check for negative weight cycles
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (distance[u] + wt < distance[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    cout << "Final shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " = " << distance[i] << endl;
    }
}
int main()


{
    int V = 4;
    vector<vector<int>> edges;

    // Adding edges: u, v, weight
    edges.push_back({0, 1, 1});  // A → B
    edges.push_back({1, 2, 2});  // B → C
    edges.push_back({2, 3, 3});  // C → D

    int src = 0; // Start from node A (0)
    bellmanFord(V, edges, src);

    return 0;

}