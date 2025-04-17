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

int main ()


{
    Node *head=NULL;
    print(head);
    insertAtTop(head,100);
    print(head);
    return 0;
}