/* 
Find the element
that appears once
 in an array of integers and every other element appears twice

*/

#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> &arr){
    int ans=arr[0];
    int count=0;
    // 3 1 5 1 5 7 9 7 9 
    for(int i=1;i<arr.size();i++){
        if(arr[i]==ans){
            count++;
        }
        ans=arr[i];
    }
    if(count==1){
        return ans;
    }
    return 0;
}


int main()
{
    vector<int> arr={3,1,5,1,5,7,9,7,9};
    cout<<findUnique(arr)<<endl;

}