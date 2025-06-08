#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;


// Function to perform BFS on a 2D matrix

/* 
 1 2 3
 4 5 6
 7 8 9

*/
void bfsInTwoDMatrix(vector<vector<int>>&matrix,int startRow,int startCol){
    //is it visited or not
    //if visited then not traverse.
    //if not visited then traverse and assign this index true.
    //if i am at index (0,0) i can go to (0,1) (1,0) (0,-1) (-1,0)
    //valid directions are right, down, left, up.
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // if i am at 0,1 that means 2 ,i can go to 0,2 (right) , 1,1 (down) , 0,0 (left) , -1,1 (up)
    int row=matrix.size();
    // if(row==0) return 0;

    int cols=matrix[0].size();
    int rowDirections[]={-1,1,0,0};
    int colDirections[]={0,0,-1,1};
    // mark all them visited?
    vector<vector<bool>> visited(row, vector<bool>(cols, false));
    queue<pair<int,int>> q;
    visited[startRow][startCol]=true;
    q.push({startRow,startCol});

    while(!q.empty()){
        auto[r,c]=q.front();
        q.pop();
        cout<<matrix[r][c]<<" ";
        //please bro search your neighbour,,
        for(int i=0;i<4;i++){
            int newRow=r+rowDirections[i];
            int newCol=c+colDirections[i];

            //check their access
            if(newRow>=0 && newRow<row && newCol>=0 && newCol<cols){
                //they are in valid neighbour
                if(!visited[newRow][newCol]){
                    //they are not visited
                    visited[newRow][newCol]=true;
                    q.push({newRow,newCol});
                }

            }
        }
    }
    
}

void dfs(vector<vector<int>>&matrix,int startRow,int startCol){
    int row=matrix.size();
    // if(row==0) return 0;

    int cols=matrix[0].size();
    int rowDirections[]={-1,1,0,0};
    int colDirections[]={0,0,-1,1};
    // mark all them visited?
    vector<vector<bool>> visited(row, vector<bool>(cols, false));
    stack<pair<int,int>> st;
    visited[startRow][startCol]=true;
    st.push({startRow,startCol});
    while(!st.empty()){
        auto[r,c]=st.top();
        st.pop();
        cout<<matrix[r][c]<<" ";
        for(int i=0;i<4;i++){
            int newRow=r+rowDirections[i];
            int newCol=c+colDirections[i];
            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < cols) {
                if (!visited[newRow][newCol]) {
                    visited[newRow][newCol]=true;
                    st.push({newRow, newCol});
                }
            }
        }
    }
}
/* 

grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]


*/

int numIslands(vector<vector<char>>& grid) {
    int row=grid.size();
    int col=grid[0].size();

     vector<vector<bool>> visited(row, vector<bool>(col, false));
     queue<pair<int,int>>q;

     int rowDirections[]={-1,1,0,0};
     int colDirections[]={0,0,1,-1};
     int count=0;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                count++;
                q.push({i,j});
                visited[i][j]=true;
            

            while(!q.empty()){
                auto[r,c]=q.front();
                q.pop();
                for(int x=0;x<4;x++){
                    int newRow=r+rowDirections[x];
                int newCol=c+colDirections[x];
                if(newRow<row && newRow>=0 && newCol<col && newCol>=0){
                    if(!visited[newRow][newCol && grid[newRow][newCol]=='1'] ){
                        visited[newRow][newCol]=true;
                        q.push({newRow,newCol});
                    }
                }
                }
            }
        }
     }
    }

     return count;
}

int main ()


{

    //lets check valid directions
    int rows=3;
    int cols=3;
    int r=2,c=2;
    /* 
    


        1 2 3
        4 5 6
        7 8 9
    */
    int rowDirections[]={0,0,-1,1};
    int colDirections[]={1,-1,0,0};
    cout<<"Valid Neighbours of ( "<< r <<" and "<< c <<" ) are :"<<endl;
    for(int i=0;i<4;i++){
        int newRow=r+rowDirections[i];//
        int newCol=c+colDirections[i];
        //check if newRow and newCol are valid indices
        if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols){
            cout<<"("<<newRow<<","<<newCol<<")"<<endl;
    }
    }


    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "BFS Traversal starting from (2,2):\n";
    // bfsInTwoDMatrix(matrix,2,2);
    dfs(matrix,0,0);
}