#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/* 
     0
    / \
   1   2
    \ / \
     3   4
          \
           5


*/

int shortestPath(int V, vector<int> adj[], int source, int dest) {
    vector<bool>visited(V,false);
    vector<int>distance(V,-1);
    queue<int>q;
    q.push(source);
    visited[source]=true;
    distance[source]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<adj[node].size();i++){
            int neighbour=adj[node][i];
            if(!visited[neighbour]){
                visited[neighbour]=true;
                distance[neighbour]=distance[node]+1;
                q.push(neighbour);
            }
        }
    }
    
    return distance[dest];
}


int main() {
    int V = 6;
    vector<int> adj[6];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3, 4};
    adj[3] = {1, 2};
    adj[4] = {2, 5};
    adj[5] = {4};

    int source = 0, destination = 1;

    int result = shortestPath(V, adj, source, destination);
    cout << "Shortest path from " << source << " to " << destination << " is: " << result << endl;

    return 0;
}