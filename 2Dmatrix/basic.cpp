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
    //we have 2 rows and 3 columns
    //let's add the first row and second row
    //1 2 3
    //4 5 6
    //5 7 9=>target

    // col[0]+col[1]+col[n];
    for(int c=0;c<col;c++){
        int sum=0;
        for(int r=0;r<row;r++){
            sum+=matrix[r][c];
           
        }
         cout<<sum<<" ";
    }    

    cout<<endl;
    cout<<"The row wise sum: "<<endl;
    //1 2 4
    // 4 5 6
    // output 7 and 15
   //row is 0,col 0+1+2
   //row is 1,col 0+1+2
    for(int r=0;r<row;r++){
        int sum=0;
        for(int c=0;c<col;c++){
            sum+=matrix[r][c];
        }
        cout<<sum<<" ";
    }
     
}