#include<iostream>
#include<vector>

using namespace std;


    int tripleSum(int a, int b){
        return a==b?(a+b)*3:a+b;
    }
    int main()
    {
        cout<<tripleSum(1,2)<<endl;//1+2=3
        cout<<tripleSum(1, 1)<<endl;//1+1=2*3=6
    }