#include<iostream>
#include<vector>
using namespace std;


int main()

{
    //lets create a 2D matrix using array
    int row,col;
    cout << "Enter number of rows and columns: ";
    cin >> row >> col;
    int matrix[row][col];
    cout << "Enter elements of the matrix:\n";
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cin >> matrix[r][c];
        }
    }
    cout<< "The matrix is:\n";
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
    //1 2 3
    //4 5 6

    //mat[0][0] = 1+mat[1][0]=1+4=5
    //mat[0][1] = 2+mat[1][1]=2+5=7
    //mat[0][2] = 3+mat[1][2]=3+6=9
    //5 7 9

     
}