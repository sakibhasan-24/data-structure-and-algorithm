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
    while(i!=id[i]){
        i=id[i];
    }
    return i;
}
//0,1,2,3,4,5,6,7,8,9,10
//4,7
void unite(int p,int q){
    int rootp=root(p);
    int rootq=root(q);
    if(rootp==rootq){
        cout<<rootp <<" and "<<rootq <<" already connected"<<endl;
    } 
    id[rootp]=rootq;
}
int main()

{

   
    int r=root(1);
    cout<<r<<endl;
    for(int i=0;i<10;i++){
        id[i]=i;
    }
    // printArray(id,10);
    
}