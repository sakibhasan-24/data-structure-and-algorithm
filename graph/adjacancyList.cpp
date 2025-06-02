#include<iostream>
#include<vector>
using namespace std;
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