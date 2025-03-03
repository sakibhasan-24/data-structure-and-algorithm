#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }

};

void print (Node *head){
    Node *temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtTop(Node* &head,int value){
    if (head==NULL){
        head=new Node(value);
        return;
    }
    Node* newNode = new Node(value);
    newNode->next=head;
    head=newNode;
}
int main() {
    Node *head= new Node(100);
    insertAtTop(head,200);
    insertAtTop(head,300);
    insertAtTop(head,400);
    insertAtTop(head,500);
    // cout<<head->data<<endl;
    print(head);
}