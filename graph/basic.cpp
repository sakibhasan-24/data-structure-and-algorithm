#include<iostream>
using namespace std;


//graph representation using adjacency matrix
/* 
Enter number of nodes: 3
Enter number of edges: 2
Enter edges (u v w):
0 1 10
1 2 5


Adjacency Matrix:
0 10 0 
0 0 5 
0 0 0 

*/

int main()



{
    int adjMatrix[100][100] = {0}; 
    int node ,edge;
    cout << "Enter number of nodes: ";
    cin >> node;
    cout << "Enter number of edges: ";
    cin >> edge;
    for(int i=0;i<edge;i++){
        int u,v,w;
        cout << "Enter edges (u v w): ";
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
    }

    //n=3 3X3 matrix
    //
    cout << "\nAdjacency Matrix:\n";
    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++){
            cout << adjMatrix[i][j] << " ";
        }
         cout << endl;
    }
       
    return 0;
}