#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        public:
        Node(int val)
        {
            data=val;
            next=NULL;
        }
};
class Stack {
    Node *top;
    int size;
    public:
        Stack(){
            top=NULL;
            size=0;
        }
        //top=NULL,
        //temp->next will point this NULL
        //20->NULL
        // top=temp

        void push(int value){
            Node *temp=new Node(value);
            temp->next=top;
            top=temp;
            size++;
        }
        void pop(){
            if(size==0 || top==NULL){
                cout<<"Stack is Empty!"<<endl;
                return;
            }
            Node *temp=top;
            top=top->next;
            size--;
            delete temp;
        }
    

};


int main ()


{
    Stack s;
    s.push(10);
    s.pop();

}