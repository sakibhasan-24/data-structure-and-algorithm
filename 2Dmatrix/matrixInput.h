
#pragma once
#include <iostream>
#include <vector>
using namespace std;
void inputMatrix(vector<vector<int>>& mat, int row, int col) {
    cout << "Enter matrix elements:\n";
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cin >> mat[r][c];
        }
    }
}


void printMatrix(const vector<vector<int>>& mat) {
    for(const auto& row : mat) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}