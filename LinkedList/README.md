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
    while (head!=NULL){
    cout<<head->data <<" "; //we print the head,then pass the head
    head =head->next;
    }


}

```
