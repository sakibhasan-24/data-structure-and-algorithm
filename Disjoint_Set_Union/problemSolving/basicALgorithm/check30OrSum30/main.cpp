/* 

Write a C++ program to check two given integers, and return true if one of them is 30 or if their sum is 30.
Sample Input:
30, 0
25, 5
20, 30
20, 25
Sample Output:
1
1
1
0

*/

#include <iostream>
using namespace std;

    bool check30OrSum30(int a, int b){
        return (a==30 || b==30 || a+b==30);
    }
    int main()

    {
        cout<<check30OrSum30(30, 0)<<endl;
        cout<<check30OrSum30(25, 5)<<endl;
        cout<<check30OrSum30(20, 30)<<endl;
        cout<<check30OrSum30(20, 25)<<endl;

    }