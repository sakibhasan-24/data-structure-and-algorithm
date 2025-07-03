/* 

Let's serve the pancake

    1)take the top one
    2)serve it
    3)put the rest on top
    4)repeat


*/



#include <iostream>
#include<stack>
using namespace std;

void servePancake(stack<int>cake){
    //base case
    if(cake.empty()){
        return;
    }
    //recursive case
    int top=cake.top();
    cake.pop();
    cout<<"Top cake is server"<<endl;

    //call
    servePancake(cake);
}


/* 

Recursion
├── Simple Recursion
├── Tree Recursion
├── Divide & Conquer
├── Dynamic Programming (Recursion + Memo)
└── Backtracking


*/