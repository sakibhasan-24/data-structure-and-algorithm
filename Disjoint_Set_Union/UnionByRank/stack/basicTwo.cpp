#include<iostream>
#include<optional>
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

        bool isEmpty(){
            return top==NULL;
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
            // if(isEmpty()){
            //     cout<<"Stack is Empty!"<<endl;
            //     return;
            // }
            Node *temp=top;
            top=top->next;
            size--;
            delete temp;
        }

        
        optional<int> peek(){
            if (top==NULL) {
                cout<<"Stack is NULL !"<<endl;
                return nullopt;
            }else {
                return top->data;
            }
        }
    

};


int main ()


{
    Stack s;

auto top = s.peek(); 

if (top.has_value()) {
    cout << "Top value is: " << top.value() << endl;
} else {
    cout << "Stack is empty!" << endl;
}

s.push(10);

top = s.peek();  

if (top.has_value()) {
    cout << "Now top value is: " << top.value() << endl;
}


}