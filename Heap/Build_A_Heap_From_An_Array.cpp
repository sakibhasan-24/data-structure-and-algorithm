#include<iostream>

using namespace std;


void heapify(int arr[],int index,int sizeOfArr){
    // Index:  0  1  2  3  4  5  6  7  8  9
//vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
//index=4,left=9,right 10
//largest=4
//arr[left(9)]>arr[largest(4)]=9>4 need update largest=left largest=9
//new largest=9
//largest(9)!=index 4 so swap...
//{3, 5, 9, 6, 9, 20, 10, 12, 18, 8};
//largest=index;
//largest=4
//index=
    int left=2*index+1;
    int right=2*index+2;
    int largest=index;
    //update arr,update largest,sizeOfarr
        if(left<sizeOfArr && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<sizeOfArr && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest,sizeOfArr);
    }
}
void buildMaxHeap(int arr[],int sizeOfArr){
    for(int i=sizeOfArr/2-1;i>=0;i--){
        heapify(arr,i,sizeOfArr);
    }
}

void printArray(int arr[],int sizeOfArr){
    for(int i=0;i<sizeOfArr;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapSort(int arr[],int sizeOfArr){
    for(int i=sizeOfArr-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}
int main()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, sizeOfArr);
    
    buildMaxHeap(arr, sizeOfArr);
    
    cout << "Max Heap: ";
    printArray(arr, sizeOfArr);
    heapSort(arr,sizeOfArr);
    cout << "Sort Heap: ";
    printArray(arr,sizeOfArr);
    return 0;
}