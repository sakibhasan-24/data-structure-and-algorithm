#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

/* 

Input:
5 3
0 1
1 2
3 4

0_____>1_________>2_______>3_______>4
0—1—2    3—4    

Output:
2

*/

void bfs(int start, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

//
void dfs(int start,vector<vector<int>&adjList,vector<bool>&visited){
    stack<int>s;
    s.push(start);
    while(!s.empty()){
        int node=s.top();
        s.pop();
      
        if(!visited[node]){
            visited[node]=true;
             cout<<node<<" ";

        }
         
        for(int i=0;i<adjList[node].size();i++){
            if(!visited[adjList[node][i]]){
                s.push(adjList[node][i]);
            }
        }
    }
}
int countComponents(int n, vector<vector<int>>& adj) {
    vector<bool>visited(adj.size(),false);
    queue<int>q;
    int count = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            // Start a new BFS from this node
            count++;
            bfs(i,adj,visited);
        }
    }
    return count;
    }
int main()


{
    vector<vector<int>> adj(100); // Adjacency list for 100 nodes
    int node ,edge;
    cout << "Enter number of nodes and edges: ";
    cin >> node >> edge;
    for(int i=0;i<edge;i++){
        int u,v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    int count= countComponents(node, adj);
    cout << "Number of connected components: ";
    cout<<count<<endl;

}