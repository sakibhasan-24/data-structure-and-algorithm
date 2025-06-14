/* 
Given a Directed Acyclic Graph (DAG) with V nodes and unit weights on each edge, find the shortest distance from a given source node to all other nodes.

If any node is unreachable, its distance should be -1

*/

// solution approach

/* 
    
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> shortestPathInDAG(int V, vector<int> adj[], int src){
    //topo sort,ensure u comes before v

    //create degree
    vector<int>indegree(V,0);
    for (int i = 0; i < V; i++)
    {
          for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
          }
    }
    //find who's indegree is 0
    queue<int>q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    //get topological order
    vector<int>topoOrder;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topoOrder.push_back(node);

        for(int nei=0;nei<adj[node].size();nei++){
            int neighbour=adj[node][nei];
            indegree[neighbour]--;


            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    //0 1 2 3 4 5
    //Now let's go calculation
    vector<int> distance(V,INT_MAX);

    distance[src]=0;
    for(int i=0;i<topoOrder.size();i++){
        int u=topoOrder[i];//its 0
        if(distance[u]!=INT_MAX){
            for(int j=0;j<adj[u].size();j++){
                int v=adj[u][j];
                if(distance[u]+1<distance[v]){
                    distance[v]=distance[u]+1;
                }
            }
        }
    }
    return distance;

}


    int main() {
    int V = 6;
    vector<int> adj[V];

    // Directed edges with unit weight
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(5);
    adj[3].push_back(5);

    int src = 0;
    vector<int> result = shortestPathInDAG(V, adj, src);

    for (int i = 0; i < V; i++) {
        cout << "Shortest distance from " << src << " to " << i << " = " << result[i] << endl;
    }

    return 0;
}

