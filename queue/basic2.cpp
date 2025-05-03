#include<iostream>
using namespace std;
class Node {
    public:
        int value;
        Node *next;

        public:
            Node(int data){
                value=data;
                next=NULL;
            }
};

class Queue {
    public:
    Node *front;
    Node *rear;
    public:
        Queue(){
            front=rear=NULL;
        }
        bool isEmpty(){
            return front==NULL;
        }
        // 2->3->4->NULL
        void push(int value){
            Node *temp=new Node(value);
            if(isEmpty()){
                front=rear=temp;
            }else {
                
                rear->next=temp;
                rear=temp;
            }
        }
        //1->2->3->NULL
        void pop(){
            if(isEmpty()){
                cout<<"Queue is Empty!"<<endl;
            }else {
                Node *temp=front;
                front=front->next;
                delete temp;
            }
        }

};
int main()

{
    
    Queue q1;
    bool c=q1.isEmpty();
    cout<<c<<endl;

}