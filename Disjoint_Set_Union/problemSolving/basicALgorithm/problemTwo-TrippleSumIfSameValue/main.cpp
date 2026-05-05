#include<iostream>
#include<vector>
/* 

Write a C++ program to compute the sum of two given integer values. If the two values are the same, then return triple their sum.
Sample Input
1, 2
3, 2
2, 2
Sample Output:
3
5
12
*/
using namespace std;


    int tripleSum(int a, int b){
        return a==b?(a+b)*3:a+b;
    }
    int main()
    {
        cout<<tripleSum(1,2)<<endl;//1+2=3
        cout<<tripleSum(1, 1)<<endl;//1+1=2*3=6
    }