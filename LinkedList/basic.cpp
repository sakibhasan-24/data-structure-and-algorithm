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
    // Node *temp=head;
    // while (temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    Node *temp=head;
    while (temp!=NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
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

void insertAtBottom(Node* &head,int value){
    if (head==NULL){
        head = new Node(value);
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *newNode = new Node(value);
    temp->next=newNode;
    // newNode->next=NULL;
}


void insertAtPosition(Node * &head,int value,int position){
    //if head is NULL
    if(head==NULL){
        Node *newNode = new Node(value);
        newNode->next=head;
        head=newNode;
        return;
    }
    if(position==1){
        Node *newNode=new Node(value);
        newNode->next=head;
        head=newNode;
        return;
    }
    int count=1;
    Node *temp=head;
    while(temp->next!=NULL && count< (position-1)){
        temp=temp->next;
        count++;
    }
    Node *newNode=new Node(value); 
    newNode->next=temp->next; 
    temp->next=newNode;  

}
int main() {
    // Node *head= new Node(100);
    // insertAtTop(head,200);
    // insertAtTop(head,300);
    // insertAtTop(head,400);
    // insertAtTop(head,500);
    // insertAtTop(head,0);
    // insertAtBottom(head,6);
    Node *head;
    insertAtPosition(head,7,1);
    insertAtPosition(head,8,1);
   
    print(head);
}