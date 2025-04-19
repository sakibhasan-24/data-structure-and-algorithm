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

void insertAtPosition(Node * &head,int value,int position){
    //A->B->C->D->F
    //i want to insert E after D.So position is 5(1 based)
    Node *temp=head;
    // if head is NULL
        if(head==NULL){
            Node *newNode=new Node(value);
            head=newNode;
            return;
        }
     //A->B->C->D->NULL ,we will insert S at position One,new list will be S->A->B->C->D->NULL
     
    if(position==1){
        Node *newNode=new Node(value);
        newNode->next=head;
        newNode->prev=NULL;
       if(head!=NULL) {
        head->prev=newNode;
       }
        head=newNode;
        return;
    }

    //Now Game is On,We need detect position
    int count=1;
    while(temp!=NULL && count<(position-1)){
        temp=temp->next;
        count++;
    }
    if(temp==NULL) {
        cout<<position<< " is out of Bound!"<<endl;
        return;
    }
        Node *newNode=new Node(value);
        //A->B->D->E->NULL
        //insert C at position 3
        //temp is Now B
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next!=NULL){
            temp->next->prev=newNode;
        }
        temp->next=newNode;
}
int main ()


{
    Node *head=NULL;
    print(head);
    insertAtTop(head,100);
    insertAtTop(head,101);
    insertAtTop(head,102);
    insertAtTop(head,103);
    // insertAtEnd(head,);
    insertAtPosition(head,200,1);
    print(head);
    return 0;
}


//Linked List has a beauty,it's just connected each other,you need to remember Head ,
//You need to focus how you connect next or prev