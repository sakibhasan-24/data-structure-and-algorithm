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
#include <typeinfo>
#include<algorithm> 
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
        next = nullptr;
    }
};

class BurgerTrain {

private:
    Node* head;

public:

    BurgerTrain() {
        head = nullptr;
    }

    // Destructor
    ~BurgerTrain() {

        Node* temp;

        while(head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    // duplicate checker...
    bool duplicateChecker(int orderID) {
        Node* temp = head;
        while(temp != nullptr) {
            if(temp->orderID == orderID) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Insert at End
    void insertAtEnd(int orderID, string burgerName, double price) {
        if(duplicateChecker(orderID)) {
            cout << "Duplicate Order ID" << endl;
            return;
        }
        Node* newNode = new Node(orderID,burgerName,  price);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // VIP Insert at Beginning
    void insertAtBegin(int orderID,string burgerName,  double price) {
        if(duplicateChecker(orderID)) {
            cout << "Duplicate Order ID" << endl;
            return;
        }
        Node* newNode = new Node(orderID,  burgerName, price);

        newNode->next = head;
        head = newNode;
    }
    // Insert at Position
    void insertAtPosition(int position,int orderID, string burgerName, double price) {
        if(duplicateChecker(orderID)) {
            cout << "Duplicate Order ID" << endl;
            return;
        }
        // Position validation
        if(position <= 0) {
            cout << "Invalid Position\n";
            return;
        }
        // Beginning insert
        if(position == 1) {
            insertAtBegin(orderID, burgerName,price);

            return;
        }

        Node* temp = head;

        // Move to previous node
        for(int i = 1;
            i < position - 1;
            i++) {

            if(temp == nullptr) {
                cout << "Invalid Position\n";
                return;
            }

            temp = temp->next;
        }

        if(temp == nullptr) {
            cout << "Invalid Position\n";
            return;
        }
        Node* newNode =
         new Node(orderID,burgerName, price);

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Order inserted successfully.\n";
    }

    // Display
    void display() {

        if(head == nullptr) {
            cout << "No Orders Available\n";
            return;
        }

        Node* temp = head;

        cout << "\n🍔 Orders List:\n";

        while(temp != nullptr) {

            cout << "ID: "<< temp->orderID<< " | Burger: "<< temp->burgerName<< " | Price: $" << temp->price << endl;

            temp = temp->next;
        }
    }

    // Count Orders
    void countOrders() {

        int count = 0;

        Node* temp = head;

        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total Orders: "  << count<< endl;
    }

    // Search By ID
    void searchByID(int orderID) {

        Node* temp = head;

        while(temp != nullptr) {
            if(temp->orderID == orderID) {
                cout << "\nOrder Found:\n";
                cout << "ID: " << temp->orderID<< endl;
                cout << "Burger: " << temp->burgerName << endl;
                cout << "Price: $" << temp->price   << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Order not found.\n";
    }

    // Delete by ID
    void deleteById(int id) {

        if(head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        // Delete head
        if(head->orderID == id) {
            Node* deleteNode = head;
          head = head->next;
            delete deleteNode;
            cout << "Order deleted successfully.\n";
            return;
        }

        Node* temp = head;

        while(temp->next != nullptr) {

            if(temp->next->orderID == id) {
                Node* deleteNode =  temp->next;
                temp->next =  temp->next->next;
                delete deleteNode;
                cout << "Order deleted successfully.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Order not found.\n";
    }

    // Reverse Linked List
    void reverseOrders() {

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while(current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
        cout << "Orders reversed successfully.\n";
    }


    // sorting linked list by price
    void bubbleSort() {
        // 99->32->102-43
        //if only one item and no itemssss
        if(head == nullptr || head->next == nullptr) {
            return;
        }
        Node* end= nullptr;
        while(end != head) {
            bool isSwapped = false;
            for (Node* current=head;current->next!=end;current=current->next){
                if(current->price > current->next->price) {
                    swap(current->price, current->next->price);
                    swap(current->burgerName, current->next->burgerName);
                    swap(current->orderID,current->next->orderID);
                    isSwapped = true;
                }
            }
            Node* temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            end=temp;
            if(!isSwapped) {
                break;
            }

        }
        // for(Node* i = head; i->next != nullptr; i = i->next) {
        //     for(Node* j = head; j->next != nullptr; j = j->next) {
        //         if(j->price > j->next->price) {
        //             swap(j->price, j->next->price);
        //             swap(j->orderID, j->next->orderID);
        //             swap(j->burgerName, j->next->burgerName);
        //         }
        //     }
        // }
        display();
        cout << "✅ Sorted using Bubble Sort (For Loop).\n";
    }

    // sort linked list using selection sort
    void selectionSort(){
        if(head == nullptr || head->next == nullptr) {
            return;
        }
        for(Node* current=head;current->next!=nullptr;current=current->next){
            Node* maxNode=current;
            for(Node* temp=current->next;temp!=nullptr;temp=temp->next){
                if(temp->price > maxNode->price){
                    maxNode=temp;
                }
            }
            if(maxNode!=current){
                swap(maxNode->price,current->price);
                swap(maxNode->orderID,current->orderID);
                swap(maxNode->burgerName,current->burgerName);
            }
        }
        display();
        cout << "✅ Sorted using Selection Sort (For Loop).\n";
    }

    // sort linked list using insertion sort
    void insertionSort(){
        if(head==nullptr || head->next==nullptr){
            display();
            return;
        }
        Node* sorted=nullptr;
        Node* current=head;
        while(current!=nullptr){
            Node* nextNode=current->next;
            if(sorted==nullptr || sorted->price >= current->price){
                current->next=sorted;
                sorted=current;
            }
            else {
                Node* temp=sorted;
                for(; temp->next!=nullptr && temp->next->price<current->price; temp=temp->next)
              {


                }
                current->next=temp->next;
                temp->next=current;
            }
            current=nextNode;
        }
        head=sorted;
        display();
        cout << "✅ Sorted using Insertion Sort.\n";
    }

};

int main() {

    BurgerTrain train;

    int choice;

    do {

        cout << "\n==========  Burger Train ==========\n";

        cout << "1. Add Order\n";
        cout << "2. VIP Order\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Order\n";
        cout << "5. Search Order\n";
        cout << "6. Display Orders\n";
        cout << "7. Count Orders\n";
        cout << "8. Reverse Orders\n";
        cout << "9. Exit\n";

        cout << "Enter Choice: ";
        if (!(cin >> choice)) {
        cout << "❌ Invalid Input! Please enter a number.\n";
    
    cin.clear();          
    cin.ignore(1000, '\n'); 
    continue;             
}
      
        
        int id;
        string name;
        double price;
        int position;

        switch(choice) {

        case 1:

            cout << "Enter ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Burger Name: ";
            getline(cin, name);

            cout << "Enter Price: ";
            cin >> price;

            train.insertAtEnd(id, name,  price);

            break;

        case 2:

            cout << "Enter VIP ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Burger Name: ";
            getline(cin, name);

            cout << "Enter Price: ";
            cin >> price;

            train.insertAtBegin(id, name,  price);

            break;

        case 3:

            cout << "Enter Position: ";
            cin >> position;

            cout << "Enter ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Burger Name: ";
            getline(cin, name);

            cout << "Enter Price: ";
            cin >> price;

            train.insertAtPosition(position, id,name,price);

            break;

        case 4:

            cout << "Enter ID to Delete: ";
            cin >> id;

            train.deleteById(id);

            break;

        case 5:

            cout << "Enter ID to Search: ";
            cin >> id;

            train.searchByID(id);

            break;

        case 6:
            int sortChoice;
            cout << "\n--- Display Options ---\n";
            cout << "1. Default (As entered)\n";
           
            cout << "2. Sort by Price (Bubble Sort)\n";
            cout << "3. Sort by Price (Insertion Sort - Upcoming)\n";
            cout << "Enter Choice: ";
            cin >> sortChoice;
             if(sortChoice==1) train.display();
            if(sortChoice==2) train.bubbleSort();
            if(sortChoice==3) train.selectionSort();
            break;

        case 7:

            train.countOrders();

            break;

        case 8:

            train.reverseOrders();

            break;

        case 9:

            cout << "Exiting Program...\n";

            break;

        default:

            cout << "Invalid Choice.\n";
        }

    } while(choice != 9);

    return 0;
}