# Linked List

### What is a Linked List?

A Linked List is a linear data structure. Each node in a linked list consists of two properties:

1. **Value** – The actual data stored in the node.
2. **Next** – A pointer that stores the address of the next node in the sequence.

Unlike arrays, linked lists do not require contiguous memory allocation, making insertions and deletions more efficient.

### Example:

```cpp
struct Node {
    int value;
    Node* next;  // This is called a self-referential property
};
```

## also we can use class

```cpp
class Node {
        public:
    int value;
    Node* next;  // This is called a self-referential property

    Node (int data){
        value = data;
        next=null
    }


};

// lets creat a linked list
int main (){
    Node *head=new Node (10);
}
```

## it's a very simple linked list we have created.

- Head means very first node in the list.
- actually we are perform almost everything in the head.
- Head (10) it means Our first Node,it a beautiful **box** .it's indicate that inside box value is **10** and
  pointing second box is for now **null**

## Operations Performed in Linked List

### 1. Insertion

- **At Head** – Insert a node at the beginning.
- **At Middle** – Insert a node at a specific position.
- **At Tail** – Insert a node at the end.

### 2. Deletion

- **From Head** – Remove the first node.
- **From Middle** – Remove a node from a specific position.
- **From Tail** – Remove the last node.

### 3. Searching

- Search for a specific value in the linked list.

## 1. Insertion

#### 1. Insert a node in the start of the list ,or we can say head

we will insert a node at the head of the list.E:G.initially linked list is 10,we will insert 12 at start position.

##### before that let's learn **traverse** a linked list.

## already we know (almost) we work on head.

Assume we have already a linked list **12->34->89->1->78** and we will print **12 34 89 1 78** .

Our **head** poiniting 12 , then we need to go 34 ,and so on until 78.
**Box** contains **12 /next location**
after print 12 ,assign 34 as **head** and print and so on until head is null.

# code

```cpp
void print (Node* head){

    //1 if head is null
    if (head == NULL) return;
    if(head->next == NULL) cout<<head->next;
    // but we need to go 34 ,and so on until head is null
    //until head is null
     // method 1
    while (head!=NULL){
    cout<<head->data <<" "; //we print the head,then pass the head
    head =head->next;
    }

    // Some issues in method 1,
    //you modified the head,
    //in future if you try to add new value ,head can be null
    // so we will use a temp variable
    Node *temp=head;
    while (temp!=NULL){
        cout<<temp->data <<" ";
        temp = temp->next
    }

}

```

# insert At the end of the list ,or we can say tail

We will insert a new node at the end of the list.e:g:12->34->42->? Now we will add new node at the end of the list

### 1. we will insert 50 after 42

### 2. we will create a new Node

### 3. we know 42 is now the last node,so it's next pointing to null

### 4. if we add 50,then 42's next pointing to 50.and 50's next pointing to null

### 5. So,we need to next null.

#### 6. Can you move head for finding existing list last items?as we add a new node in the last.whenever we get next==Null it means this is last,we will add after it.

#### 7.we can move head for finding existing list but it lost our reference for head,next time it will poiniting last node as head.

#### 8. we will create a temp node.it will initialize with head.

#### 9. temp will move **temp=temp->next** until temp->next is not equal to null.

#### 10. null found,So,we need to add .**temp->next=newNode**

```cpp

 void insertAtBottom(Node *head ,int value){
    //may be head is null
    if (head == NULL){
        head=new Node(value);
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node *newNode = new Node(value);
    temp->next=newNode;

 }
```

# Let's learn insert At Your favourite position.

1.may be head is null
2.may be insert at position 1.(head is null and insert at position 1 both is same 😂)

### N.B:we assume linked list is 1 based

for insert at position 1 ,it means insert at head,So,its simple,create a new node,**newNode next will point head** and head will be new Node.

Now for most interesting part,if we want insert at particular position,eg: **23->89->5->12->1->Null** we want to insert at postion **3** and the value will be **100**.

What we will do?
Now at position 3 ,here value is 5 and it's next pointing to 12 and its previous value 89 ,it's next poinitng 5.Our Goal is **23->89->100->5->12->1->Null**.
So, Now new Node is 100,new Node's next will poinitng 5(before it was(5) pointed by 89).and 89's next will pointing 100(before 89 pointing 5)
it's all about moving the pointer next.

let's write the code.

- **Pointer Adjustments:**
- `newNode->next = temp->next;` (100 should point to 5)
- `temp->next = newNode;` (89 should now point to 100)

**It’s all about correctly updating the `next` pointers!**

---

## Code Implementation

```cpp



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
```

# Let's move delete the node from the list

Now we can also follow,delete the from head,tail and giving index.

# delete the node from head

- **Delete From Head:**
- Head is null ,nothing to delete here.
- Only head is single node.so just delete the head.
- Now we have a list of nodes.
- `we don't want to lose our head reference` So,we will create a temp variable.it will point head,next head will be this temp,then delete temp.

- **Delete From Tail:**
- Head is null ,nothing to delete here.
- Only head is single node.so just delete the head.
- Now we have a list of nodes.
- `we don't want to lose our head reference` So,we will create a temp variable.it will point head.
- `A->B->C->D->E->F->null` So,we will create a temp variable.it will point head.
- **A is Now head,and also our temp** .We will delete **F** and also need to ensure **E** pointing NULL.
- We will Move with temp.Temp will stop at **E** .**temp->next is F,we will Do two things,temp->next will assign as NULL and temp->next will be deleted**.

- **Delete From Position:**
- Head is null ,nothing to delete here.
- Only head is single node.so just delete the head.
- Now we have a list of nodes.
- `we don't want to lose our head reference` So,we will create a temp variable.it will point head.
- `A->B->C->D->E->F->null` So,we will create a temp variable.it will point head.
- **A is Now head,and also our temp** .We will delete **C** .
- We will Move with temp.Temp will stop at **B** .**temp->next is C,we will Do two things, temp->next=temp->next->next;will delete and temp->next will be deleted**.
