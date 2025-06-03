#include<iostream>
#include<vector>
using namespace std;


//void bfs traversal
// we need to use queue
// need a visited array to keep track of visited nodes
// if visited[i] = true, then node i is visited
// if visited[i] = false, then node i is not visited
//0-{1,3}
//1-{0,2}
//2-{1,3}

/* 
    Graph:
0: 1 2
1: 0 2
2: 0 1 3
3: 2


adjList[0] = {1, 2}
adjList[1] = {0, 2}
adjList[2] = {0, 1, 3}
adjList[3] = {2}
for (int i = 0; i < adjList[2].size(); i++) {
    // Look at each neighbor of 2: adjList[2][0], adjList[2][1], adjList[2][2]
}



*/
void bfs(int start,vector<vector<int>>&adjList){
    vector<bool> visited(adjList.size(),false);
    vector<int> q;
    visited[start]=true;
    q.push_back(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout << node << " ";
        for(int i=0;i<adjList[node].size();i++){
            if(!visited[adjList[node][i]]){
                visited[adjList[node][i]]=true;
                q.push_back(adjList[node][i]);
            }
        }
    }

}
int main()


{

    int node,edge;
    cout << "Enter number of nodes and edges : ";
    cin >> node >> edge;
    vector<vector<int>> adjList(node); 
    for(int i=0;i<edge;i++){
        int u,v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;//10 20 adjlist[10].push_back(20);
        adjList[u].push_back(v); //10->20
        adjList[v].push_back(u); //20->10 (for undirected graph)
    }
    cout << "\nAdjacency List:\n";
    for(int i=0;i<node;i++){
        cout << i << " -> ";
        for(int j=0;j<adjList[i].size();j++){
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}