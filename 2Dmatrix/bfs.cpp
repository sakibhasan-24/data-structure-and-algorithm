#include<iostream>
#include<queue>
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
    int row=matrix.szie();
    if(row==0) return 0;

    int cols=matrix[0].size();
    int rowDirections[]={-1,1,0,0};
    int colDirections[]={0,0,-1,1};
    // mark all them visited?
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
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
}