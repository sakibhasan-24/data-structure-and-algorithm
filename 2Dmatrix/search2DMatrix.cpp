#include<iostream>
#include<vector>


using namespace std;

/* 
 1 3 5 7
 10 11 16 20
 23 30 34 60

*/

bool searchMatrix(vector<vector<int>>& matrix, int target){
    int row=matrix.size();
    int col=matrix[0].size();
    // i am at 7
    //if my target less than seven then i will decrease my col upto 0
    //if my target greater than seven i will increase my row and last col
/* 
 1 3 5 7
 10 11 16 20
 23 30 34 60

 target 3
r=0,col=3
//mat[0][3]=7 which is greater than target so c--c,c is now 2
//mat[0][2]=5 which is greater than target so c--,c is now 1
//
*/
    int r=0;
    int c=col-1;
    while(c>=0 && r>=row){
        if(matrix[r][c]>target){
            c--;
        }
        if(matrix[r][c]<target)
        {
            if(r<row){
                r++;
            }
            
        }
        else if(matrix[r][c]==target) {
            return true;
        }
    }
    return false;
}
vector<vector<int>> indexInFound(vector<vector<int>>& mat, int target){
     vector<vector<int>> res;
    for(int r=0;r<mat.size();r++){
        for(int c=0;c<mat[0].size();c++){
            if(mat[r][c]==target){
                res.push_back({r,c});
            }
        }
    }
    return res;
    
}
int main()


{

    int row,col;
    cout<<"Enter Row and col : "<<endl;
    cin>>row>>col;
    cout<<endl;
    vector<vector<int>> matrix(row, vector<int>(col));
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cin>>matrix[r][c];
        }
    }

    
    cout<<endl;
    cout<<"Enter the target number: "<<endl;
    int target;
    cin>>target;
    vector<int>ans;
   vector<vector<int>> res = indexInFound(matrix, target);
        for (auto p : res) {
        cout << "Found at (" << p[0] << ", " << p[1] << ")\n";
    }
}