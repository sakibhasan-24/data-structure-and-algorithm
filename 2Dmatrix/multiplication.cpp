#include<iostream>
#include<vector>


using namespace std;


vector<vector<int>> multiplyMatrices(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int rowsA = a.size();
    int colsA = a[0].size();
    int rowsB = b.size();
    int colsB = b[0].size();

    // Check if multiplication is possible
    if (colsA != rowsB) {
        throw invalid_argument("Number of columns in A must be equal to number of rows in B");
    }

    // Initialize the result matrix with zeros
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    // Perform matrix multiplication
    // 1*7+2*9+3*11 1*8+2*10+3*12
    // 4*7+5*9+6*11 4*8+5*10+6*12
    for(int i=0;i<rowsA;i++){
        for(int j=0;j<colsB;j++){
            result[i][j] = 0;
            for(int k=0;k<colsA;k++){
                result[i][j] += a[i][k] * b[k][j];//result[0][0]+=a[0][0]*b[0][j]=1*7
            }
        }
    }

/* 
58 64
139 154

// Matrix A (2x3)
vector<vector<int>> A = {
    {1, 2, 3},
    {4, 5, 6}
};

// Matrix B (3x2)
vector<vector<int>> B = {
    {7, 8},
    {9, 10},
    {11, 12}
};




*/
    // Perform matrix multiplication
   
    
    return result;
}

int main ()


{
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter dimensions of first matrix (rows cols): ";
    cin >> rowsA >> colsA;
    cout << "Enter dimensions of second matrix (rows cols): ";
    cin >> rowsB >> colsB;

    vector<vector<int>> a(rowsA, vector<int>(colsA));
    vector<vector<int>> b(rowsB, vector<int>(colsB));

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cin >> b[i][j];
        }
    }

    try {
        vector<vector<int>> result = multiplyMatrices(a, b);
        cout << "Resultant matrix:\n";
        for (const auto& row : result) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}