/* 

Write a C++ program to check two given integers, and return true if one of them is 30 or if their sum is 30.


*/




#include <iostream>
using namespace std;


bool test(int a, int b){
    if(a==30 || b==30 || a+b==30){
        return true;
    }
    return false;
}


int main(){
     cout << test(30, 0) << endl;  
    cout << test(25, 5) << endl; 
    cout << test(20, 30) << endl; 
    cout << test(20, 25) << endl;     
    return 0;  
}