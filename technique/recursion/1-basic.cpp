#include<iostream>
#include<vector>
using namespace std;
int factorial(int n){
    //n*n-1;5*

    if(n==0) return 1;
    return n*factorial(n-1);
}

//first iterations
//number =5
//n!=5 so 5*fact(5-1);
                //fact(4)
                    fact(3)
                        fact(2)
                            fact(1)
                                fact(0)==1
//in the stack i put 5,then 4 then 3 then 2 then 1 then 0
//then i start pop 0 ,it return 1 ,the pop 1 it return 1 then pop 2 it return 2 then pop 3 it return 6 then pop 4 it return 24 then pop 5 it return 120

int main()

{

}