// heap is a data structure that allows for efficient priority queue operations.
// two types of heaps are commonly used: min-heap and max-heap.
// a min-heap is a complete binary tree where the value of each node is less than or equal to the values of its children.
//    a max-heap is a complete binary tree where the value of each node is greater than or equal to the values of its children.
/* 
    conditon
    1. complete binary tree
    2. min heap property: parent node is less than or equal to its children
    3. max heap property: parent node is greater than or equal to its children
    4. heap is implemented using an array, where the root is at index 0
    5. for a node at index i, its left child is at index 2*i + 1 and its right child is at index 2*i + 2
    6. for a node at index i, its parent is at index (i - 1) / 2
*/

#include <iostream>
#include <vector>
using namespace std;


class MaxHeap{
    vector<int>heap;
    public:
    MaxHeap() {}
    int getParent(int index){
        return (index - 1) / 2;
    }
    int getLeftChild(int index){
        return 2 * index + 1;
    }
    int getRightChild(int index){
        return 2 * index + 2;
    }

    //10 
    void insert(int value){
        //if heap is empty, insert the value at index 0

        //10 40
        //new insert index=1
        //his parent index=0
        // now its 40 and 10
        //new root is 40 and 10 is its child
        heap.push_back(value);
        int newInsertIndex = heap.size() - 1;
        while(newInsertIndex>0){
            int parentIndex=getParent(newInsertIndex);
            if(heap[parentIndex]< heap[newInsertIndex]){
                //we need to swap the parent and the new insert value
                swap(heap[parentIndex], heap[newInsertIndex]);
                //Now we need to update the new insert index to the parent index
                newInsertIndex = parentIndex;
            }else{
                //if the parent is greater than or equal to the new insert value, we can stop
                break;
            }
        }
        //insert the value at the end of the heap
        //insert 10 at index 0
        //insert 20 at index 1
        //insert 30 at index 2
    }

    void heapifyDown(int i=0){
        int largest=i;
        int size=heap.size();
         while(i<size){
            int r=getRightChild(i);
            int l=getLeftChild(i);
            if(l<size &&  heap[l]>heap[largest]){
                larget=i;
            }
            if(r<size && heap[r]>heap[largest]){
                larget=i;
            }
            if(largest!=i){
                swap(heap[i],heap[largest]);
                i=largest;
            }else {
                break;
            }
         }
    }
    void deleteHeap(){
        if(heap.size()==0){
            cout<<"Heap is empty"<<endl;
            return;
        }

        heap[0]=heap.back();
        heap.pop_back();

        heapifyDown(0);
    }
    
};
int main()



{
    MaxHeap heap;
    heap.insert(10);
    heap.insert(6);
    heap.insert(100);
    heap.insert(30);
    heap.insert(90);

    return 0;
}