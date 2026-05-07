/* Burger Train Express — Linked List OOP Project
📖 Problem Statement

You are building a funny restaurant management system called

Burger Train Express

Every burger order is connected like train compartments.

Each order contains:

Order ID
Burger Name
Price

Orders are stored using a Singly Linked List.

Your task is to build the system using C++ OOP (Object-Oriented Programming).

🎯 Features to Implement
 1. Add Order at End

New customer orders go to the end of the train.

 2. VIP Order at Beginning

VIP customers are inserted at the beginning.

 3. Insert Order at Position

Insert a burger order at any specific position.

 4. Delete Order by ID

Cancel an order using its ID.

 5. Display All Orders

Print all burger orders.

 6. Search Burger by Name

Find a burger and show its position.

 7. Count Total Orders

Display total number of orders.

 8. Reverse the Burger Train

Reverse the linked list.

 9. Find Middle Order

Use slow and fast pointer technique. */

#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        int orderID;
        string burgerName;
        double price;
        Node* next;

        Node(int orderID, string burgerName, double price) {
            this->orderID = orderID;
            this->burgerName = burgerName;
            this->price = price;
            this->next = nullptr;
        }
}

class BurgerTrain {

    private:
        Node* head;
    public:
       
        BurgerTrain() {
            head = nullptr;

        }
    void insertAtEnd(int orderID, string burgerName, double price) {
        Node* newNode=new Node(orderID, burgerName, price);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        // if already have nodes
        //1->2->3->4->5->6->nullptr
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
     
    }

    // vip order(beginner insert)
    void insertAtBegin(int orderID, string burgerName, double price) {
        Node* newNode = new Node(orderID, burgerName, price);
        if(head == nullptr) {
            head = newNode;
            return;
        }
         // if already have nodes
        //1->2->3->4->5->6->nullptr
        //1 is now temp
        //head=newNode(orderID, burgerName, price);
        //head->next=temp;
        Node* temp = head;
        head = newNode;
        head->next = temp;
    
    }
}
int main() {
    

    BurgerTrain train;
}