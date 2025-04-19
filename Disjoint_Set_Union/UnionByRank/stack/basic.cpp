// Stack is a linear Data structure
//follow LIFO
//operations are =>push,pop,top,isEmpty



#include<iostream>

using namespace std;


class Stack{
    int *box;
    int size;
    int top;


    public:
        Stack(int s){
           size=s;
            top=-1;
            box=new int[size];
        }
};

int main ()


{

}