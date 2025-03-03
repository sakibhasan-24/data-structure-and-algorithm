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
