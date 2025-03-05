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


// delete from head

void deleteFromHead(Node* &head){
    if (head==NULL) {
        cout<<"List is empty, cannot delete from head."<<endl;
        return;
    }
    if(head && head->next==NULL){
        cout<<"Only we have head "<<endl;
        delete head;
        head=NULL;
        return ;
    }
    Node *temp=head;
    head=head->next;
    delete temp;
}

void deleteFromTail (Node* &head){
    if(head==NULL){
        cout<<"List is empty, cannot delete from tail."<<endl;
        return;
    }
    if(head->next==NULL){
        cout<<"Only we have head "<<endl;
        delete head;
        head=NULL;
        return;
    }
    //1-2-3-4-5-6
    cout<<"Hitted"<<endl;
    Node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    delete temp->next;
}

void deleteFromPosition(Node * &head,int position){
    if(head==NULL){
        cout<<"List is empty, cannot delete from position."<<endl;
        return;
    }
    if(position==1){
        Node *temp=head;
        head=temp->next;
        delete temp;
        return;
    }
    //A->B->C->D->E->F->NULL ,we will delete index 3 ,which is C.new result will be A->B->D->E->F->NULL
    Node *temp=head;
    int count=1;
    while(temp->next!=NULL && count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        cout<<"Index out of range. Cannot delete from position."<<endl;
        return;
    }
    temp->next=temp->next->next;
    delete temp->next;
}
int main() {
    // Node *head= new Node(100);
    // insertAtTop(head,200);
    
    // insertAtTop(head,0);
    // insertAtBottom(head,6);
    Node *head;
    insertAtPosition(head,7,1);
    insertAtTop(head,300);
    insertAtTop(head,400);
    insertAtTop(head,500);
    insertAtTop(head,600);
    insertAtTop(head,700);
    // insertAtPosition(head,8,1);
    // deleteFromHead(head);
    // deleteFromHead(head);
    // deleteFromHead(head);
    // deleteFromHead(head);
    // deleteFromTail(head);
    // deleteFromTail(head);
    // deleteFromTail(head);
    // deleteFromTail(head);
    // deleteFromTail(head);
    deleteFromPosition(head,3);
    deleteFromPosition(head,30);
    // deleteFromPosition(head,1);
    // deleteFromPosition(head,2);
    // deleteFromPosition(head,3);
    // deleteFromPosition(head,1);
   
    print(head);
}