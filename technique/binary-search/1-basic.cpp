// Binary Search Core Philosophy
// 1. Divide and Conquer
// 2. The array must be sorted
// 3. The array must be of fixed size
// 4. Always reduce the size of the search space by half



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1 2 3 4 5 6 7 8 target 5
int binarySearch(vector<int> &arr, int target) {
    int low=0;
    int high=arr.size()-1;//7

    while(low<=high) {
        int mid=low+(high-low)/2;//0+(7-0)/2=

        if(arr[mid]==target) {
            return arr[mid];
        } else if(arr[mid]<target) {
            //target in my right side
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
     return -1;  
    
}