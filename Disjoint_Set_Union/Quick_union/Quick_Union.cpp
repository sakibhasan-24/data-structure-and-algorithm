#include<iostream>
using namespace std;
int id[10];
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int root(int i){
    // cout<<i<<endl;
    while(i!=id[i]){
        i=id[i];
    }
    return i;
}
void unite(int p,int q){
    int rootp=root(p);
    int rootq=root(q);
    // cout<<rootp<<endl;
    if(rootp==rootq){
        cout<<rootp <<" and "<<rootq <<" already connected"<<endl;
    } 
    id[rootp]=rootq;
}
int main()

{  
    int r=root(5);
    cout<<r<<endl;
    // int r=root(5);
    // cout<<r<<endl;
    for(int i=0;i<10;i++){
        id[i]=i;
    }
    unite(0,5);
    printArray(id,10);
   
    
}