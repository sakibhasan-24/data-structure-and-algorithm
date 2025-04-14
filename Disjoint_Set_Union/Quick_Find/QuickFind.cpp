#include<iostream>
using namespace std;
int id[10];
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


bool isConnected(int p,int q){
    return id[p]==id[q];
}
//0,1,2,3,4,5,6,7,8,9
void unit(int p,int q){
    bool check=isConnected(p,q);
    if(check) {
        cout<<"Connected already"<<endl;
       
    }else{
 int pid=id[p];
    int qid=id[q];
    for(int i=0;i<10;i++){
        if(id[i]==pid){
            id[i]=qid;
        }
    }
    }
    // 0,1,2,3,4,5,6,7,8,9
    //2,3
   
}
int main()

{

   
    for(int i=0;i<10;i++){
        id[i]=i;
    }
    printArray(id,10);
    cout << "Are 0 and 1 connected? " << (isConnected(0, 1) ? "Yes" : "No") << endl;

    unit(0,1);
    printArray(id,10);
}