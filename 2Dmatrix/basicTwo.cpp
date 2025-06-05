#include<iostream>
#include<vector>
#include<climits>
using namespace std;

pair<int, pair<int, int>> findMaxClickLocation(const vector<vector<int>>& heatmap) {
    int maxClicks = INT_MIN;
    pair<int, int> maxPos = {-1, -1};
    

    return {maxClicks, maxPos};  

}

int main ()

{
    //lets create a 2D matrix using vector
    int row, col;
    cout << "Enter number of rows and columns: ";
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    
    cout << "Enter elements of the matrix:\n";
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cin >> matrix[r][c];
        }
    }
    cout << "The matrix is:\n";
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }

    cout<<"Transpose Matrix : "<<endl;
    // 1 2 3
    // 4 5 6


    //target=>1 4
            //2 5
            //3 6
    //here we have 2 rows and 3 cols
    //now we will convert it 3 rows and 2 col
    // row[0]col[0] 
    //row[1] col[0]

    // vector<vector<int>>transpose(row,vector<int>(col));
    vector<vector<int>> transpose(col, vector<int>(row));

    for (int r=0; r<row; r++) {
    for (int c=0; c<col; c++) {
        transpose[c][r] = matrix[r][c];
    }
}
    for (int r=0; r<col; r++) {
        for (int c=0; c<row; c++) {
            cout << transpose[r][c] << " ";
        }
        cout << endl;
    }

    
    
    return 0;
}