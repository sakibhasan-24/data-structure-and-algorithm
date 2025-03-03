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
