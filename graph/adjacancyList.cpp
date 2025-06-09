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

// 0: 1 2
// 1: 0 2
// 2: 0 1 3
// 3: 2


void dfs(int start,vector<vector<int>>&adj){
    vector<bool> visited(adj.size(),false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while(!s.empty()){
        int node=s.top;
        s.pop();
        cout << node << " ";
        for(int i=adj[node].size()-1;i>=0;i--){
            if(!visited[adj[node][i]]){
                visited[adj[node][i]] = true;
                s.push(adj[node][i]);
            }
        }
    }
}
//
/* 
    0 1
    1 0

*/
 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(grid[0][0]==1 || grid[row-1][col-1]==1) return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<bool>>visited(row,vector<bool>(col,false));
       
        visited[0][0]=true;
        int rowDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
     int colDir[] = {-1, 0, 1, -1, 1, -1, 0, 1}
      int res=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto[r,c]=q.front();
                q.pop();
                if(r=row-1 && c=col-1){
                    return res;
                }
                for(int z=0;z<8;z++){
                    int nr=r+rowDir[z];
                    int nc=c+colDir[z];
                    if(nr>=0 && nr<row && nc>=0 && nc<col){
                        if(!visited[nr][nc] && grid[nr][nc]==0){
                            visited[nr][nc]=true;
                            q.push({nr,nc});
                        }
                    }
                }
            }

        }
        return res;
    }

/* 
// 0: 1 2
// 1: 0 2
// 2: 0 1 3
// 3: 2

*/

void currectDFS(int start,vector<vector<int>>&adjList){
    vector<bool>visited(adjList.size(),false);
    stack<int>s;
    s.push(start);
    visited[start]=true;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        cout << node << " ";
        //after popping the node, we make it visited
        visited[node]=true; 
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