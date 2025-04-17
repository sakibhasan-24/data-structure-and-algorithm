// //let's dive into doubly linked list


#include<iostream>
using namespace std;
class  Node  {
    public:
    int value;
    Node *next;
    Node *prev;

    Node (int data){
        value=data;
        next=NULL;
        prev=NULL;
    }
 
};

void print (Node *head){
   
    Node *temp=head;
    if(temp==NULL) cout<<" Please Insert Some Node!"<<endl;
    while (temp!=NULL){
        cout<<temp->value <<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void   insertAtTop(Node* &head,int value){
    if(head==NULL){
        Node* newNode=new Node(value);
        head=newNode;
        return;
    }
    Node *newNode=new Node(value);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
   
}
void insertAtEnd(Node* &head,int value){
    Node *temp=head;
    if(temp==NULL){
        Node* newNode=new Node(value);
        head=newNode;
        return;
    }
    //detect last
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(value);
    
    temp->next=newNode;
    newNode->prev=temp;

}

int main ()


{
    Node *head=NULL;
    print(head);
    insertAtTop(head,100);
    insertAtTop(head,101);
    insertAtTop(head,102);
    insertAtTop(head,103);
    insertAtEnd(head,2000);
    
    print(head);
    return 0;
}