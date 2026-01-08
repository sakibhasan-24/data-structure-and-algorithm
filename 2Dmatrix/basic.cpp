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

    cout<<endl;
    //find diagonal matrix;

    if(row!=col){
        cout<<"It should be NXN size:(3X3 or 4X4) "<<endl;
        return -1;
    }
    //1 2 3 
    //4 5 6
    //7 8 9
    //output 1 5 9
    cout<<"Primary Diagonal: "<<endl;
    cout<<endl;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            if(r==c){
                cout<<matrix[r][c]<<" "; 
            }
        }
    }   
    cout<<endl;
    //1 2 3 mat[r=0][col 2]
    //4 5 6 mat[r=1]col[1]
    //7 8 9 mat [r=2] col[0]
    //output 3 5 
     cout<<"Secondary Diagonal: "<<endl; 
     
     for(int r=0;r<row;r++){
        int c=col-1-r;
            cout<<matrix[r][c]<<" "; 
        
     } 

}


/* 

 ==============================
2D MATRIX PRACTICE (ARRAY)
==============================

1. Input Handling
- Took number of rows and columns from user
- Created a 2D matrix
- Filled matrix elements using nested loops

2. Matrix Display
- Printed the matrix row by row using nested loops

3. Column-wise Sum
- For each column:
  - Initialized sum = 0
  - Traversed all rows for that column
  - Added matrix[row][col]
- Printed sum of each column

4. Row-wise Sum
- For each row:
  - Initialized sum = 0
  - Traversed all columns for that row
  - Added matrix[row][col]
- Printed sum of each row

5. Square Matrix Check
- Checked if rows == columns
- If not square, diagonals are not possible

6. Primary Diagonal
- Condition: row index == column index
- Printed elements where r == c
- Example: matrix[0][0], matrix[1][1], matrix[2][2]

7. Secondary Diagonal
- Column index calculated as: col - 1 - row
- Printed elements:
  - matrix[0][n-1]
  - matrix[1][n-2]
  - matrix[2][n-3]

Concepts Used:
- 2D Arrays
- Nested Loops
- Index Manipulation
- Row-wise vs Column-wise Traversal
- Diagonal Logic in Matrix

Time Complexity:
- Matrix input & display: O(rows × cols)
- Row sum: O(rows × cols)
- Column sum: O(rows × cols)
- Diagonal traversal: O(n)

Important Note:
- Used array-based matrix
- Variable Length Array works in some compilers but vector is safer in standard C++

==============================
END NOTE
==============================


*/