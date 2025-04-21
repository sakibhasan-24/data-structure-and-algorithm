#include<iostream>
#include<vector>
#include<string>
using namespace std;

//queue is a linear data structure
//queue also can implement using array and linked list

void message(string msg){
    cout<<msg;
}
class Queue{
    int *arr;
    int front,rear;
    int size;

    public:
    Queue(int n){
        size=n;
        front=-1,rear=-1;
        arr=new int [n];
    }

    bool isEmpty(){
        return rear==-1;
    }
    bool isFull(){
        return rear==size-1;
    }
    //rear=-1,front=-1
    void push(int value){
        if(isFull()){
            cout<<"Queue is Full!!!!!!!!!!!!"<<endl;
            return;
        }else if(isEmpty()){
            front=rear=0;
            arr[front]=value;
        }else {
            // rear++;
            // make it circular
            rear=(rear+1)%size;
            arr[rear]=value;
        }

    }

    void pop(){
        if(isEmpty()){
            message("Queue is Empty!");
        }
        else if(rear==front){
            rear=front=-1;
        }else {
            // front=front+1;
            // make it circular
            front=(front+1)%size;
        }
    }
};

int main ()


{
    Queue q1(5);
    q1.pop();
    q1.push(100);
    q1.pop();
    return 0;
}