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
    Node *newNode = new Node(value);
    temp->next=newNode;

 }
```
