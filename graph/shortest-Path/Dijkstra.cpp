#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dijkstra(int V,vector<vector<vector<int>>> adj,int src){
    //
    vector<int>visited(V,false);
    //f f f f  f
    //0 X X X X 
    vector<int>distance(V,INT_MAX);
    distance[src]=0;
    for(int i=0;i<V;i++){
        int node=-1;
        int value=INT_MAX;
        for(int j=0;j<V;j++){
            if(!visited[j] && value>distance[j]){
                value=distance[j];
                node =j;
            }
        }
        if (node == -1) break;

        visited[node]=true;
        
        for(int k=0;k<adj[node].size();k++){
            int neighbour = adj[node][k][0];
            int weight = adj[node][k][1];
            if(distance[neighbour]>distance[node]+weight && !visited[neighbour]){
                // distance[neighbour]=distance[node]+weight;
                distance[neighbour] = distance[node] + weight; 

            }
        }
    }
    return distance;
}

int main()


{
    int V = 4;
    vector<vector<vector<int>>>adj(V);

    // Graph:
    // 0 --1--> 1
    // 0 --4--> 2
    // 1 --2--> 2
    // 2 --3--> 3

    adj[0].push_back({1, 1});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 2});
    adj[2].push_back({3, 3});

    vector<int> result = dijkstra(V, adj, 0);

    for (int i = 0; i < V; i++) {
        cout << "Shortest distance to node " << i << " = " << result[i] << endl;
    }
    
}