// Stack is a linear Data structure
//follow LIFO
//operations are =>push,pop,top,isEmpty



#include<iostream>

using namespace std;


class Stack{
    int *box;
    int size;
    int top;


    public:
        Stack(int s){
           size=s;
            top=-1;
            box=new int[size];
        }
        ~Stack() {
            delete[] box;
        }
        bool isEmpty(){
            return top==-1;
        }
        bool isFull (){
            return top==size-1;
        }
        void push(int value) {
            if (isFull()) {
                cout<< "Stack Overflow: Cannot add value " << value << "!\n";
                return;
            }
            box[++top] = value;
            cout << " Pushed " << value << " at position " << top << ".\n";
        }
    

        void pop() {
            if (isEmpty()) {
                cout << " Stack Underflow: Stack is already empty!\n";
                return;
            }
            cout << " Popped " << box[top--] << " from the stack.\n";
        }
        int peek()  {
            if (isEmpty()) {
                cerr << " Stack is Empty! Cannot peek.\n";
                return -1; 
            }
            return box[top];
        }
        void display()  {
            if (isEmpty()) {
                cout << " Stack is empty.\n";
                return;
            }
    
            cout << "Stack contents (top to bottom): ";
            for (int i = top; i >= 0; --i) {
                cout << box[i] << " ";
            }
            cout << "\n";
        }
    
        
};

int main ()


{
    Stack s(7);
    s.pop();
}