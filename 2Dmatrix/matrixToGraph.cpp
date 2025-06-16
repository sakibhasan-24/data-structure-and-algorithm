// rows = 3, cols = 3

// (i, j):     Corresponding ID (i * cols + j)

// (0, 0)  →  0 * 3 + 0 = 0  
// (0, 1)  →  0 * 3 + 1 = 1  
// (0, 2)  →  0 * 3 + 2 = 2  
// (1, 0)  →  1 * 3 + 0 = 3  
// (1, 1)  →  1 * 3 + 1 = 4  
// (1, 2)  →  1 * 3 + 2 = 5  
// (2, 0)  →  2 * 3 + 0 = 6  
// (2, 1)  →  2 * 3 + 1 = 7  
// (2, 2)  →  2 * 3 + 2 = 8

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 void buildGraphFromMatrix(vector<vector<int>> &matrix) {

    int rows=matrix.size();
    int cols=matrix.size();
    vector<vector<int>>adj(rows*cols);
    int rowDir[] = {-1, 1, 0, 0};  
    int colDir[] = {0, 0, -1, 1}; 

    for (int r = 0; r < rows; r++)
    {
        for(int c=0;c<cols;c++){
            int nodeId= r*cols+c;//0*3+0=0
            cout<<nodeId<< " "<<r<<" "<<" "<<cols<<" "<<c<<endl;
            for(int k=0;k<4;k++){
                int newRow = r + rowDir[k];
                int newCol = c + colDir[k];
                if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols){
                    int newNodeId=newRow*cols+newCol;// 
                    adj[nodeId].push_back(newNodeId);
            }
        }
    }
    
 }
 // Print adjacency list
    cout << "Adjacency List:\n";
    for (int node = 0; node < rows * cols; ++node) {
        int i = node / cols;
        int j = node % cols;
        cout << "Node (" << i << "," << j << ") [" << node << "] -> ";
        for (int neighbor : adj[node]) {
            int ni = neighbor / cols;
            int nj = neighbor % cols;
            cout << "(" << ni << "," << nj << ") [" << neighbor << "] ";
        }
        cout << endl;
    }

}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    buildGraphFromMatrix(matrix);
    return 0;
}