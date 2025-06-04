#include<iostream>
#include<vector>

#include "matrixInput.h"

using namespace std;
/* 
    input 
 1   2   3   4   5
 6   7   8   9  10
11  12  13  14  15
16  17  18  19  20
21  22  23  24  25
output

1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13

//starting from row[0]and col[0] ,then col increase,until col<col.size ,then row increase 

*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int row=matrix.size();
        int col=matrix[0].size();
        int top=0;
        int right=col-1;
        int bottom=row-1;
        int left=0;
        /*  l
           t 1 2 3 r//done
             4 5 6
           b 7 8 9
            output 1 2 3 6 9 8 7 4 5
             0 2 0 1
        */


       while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res.push_back(matrix[top][i]);
        }
        top--;
        for(int j=top;j<=bottom;j--){
            res.push_back(matrix[j][right]);
        }
        right--;
        if(top<=bottom){
            for(int k=right;k>=left;k--){
                res.push_back(matrix[bottom][k]);
            }
            bottom--;
        }
        if(left<=right){
            for(int k=bottom;k>=top;k--){
                res.push_back(matrix[k][left]);
            }
            left--;
        }
       }
            

        return res;

    }
int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    inputMatrix(matrix, row, col);
}
