#include<iostream>
using namespace std;


class Node {
    public:
        int data;
        Node *next;
        Node *prev;

    Node (int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

Class Dequeue{
    Node *front;
    Node *rear;
    public:
        Dequeue(){
            front=rear=NULL:
        }

        void isEmpty(){
            if(front==NULL) return true;
        }
        //1->null
        void push_front(int x){
            if(isEmpty()){
                Node newNode=new Node(x);
                front=newNode;
                rear=newNode;
                return;
            }else {
                Node newNode=new Node(x);
                newNode->next=front;
                front->prev=newNode;
                front=newNode;
                return;
            }
        }
        void push_back(int x){
            //1-2-3-null
            if(isEmpty()){
                Node newNode=new Node(x);
                front=rear=newNode;
                return;
            }else {
                Node newNode=new Node(x);
                rear->next=newNode;
                newNode->prev=rear;
                rear=newNode;
                return;
            }
        }

};

int main()


{



}