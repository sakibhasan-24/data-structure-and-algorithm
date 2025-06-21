#include<iostream>
#include<vector>
using namespace std;


int main ()


{
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>>n;
    vector<int>res(n);
    cout<<"Enter the array elements "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    //prefix sum
    vector<int>prefix(n);
    prefix[0]=res[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+res[i];
    }
    //[10,20,30,40,50]
    cout<<"the Prefix sum is "<<endl;
    for(int i=0;i<n;i++){
        cout<<prefix[i]<<" ";
    }
}