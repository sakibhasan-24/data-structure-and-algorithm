/* 
divide and conquer is an algorithm design paradigm. A divide-and-conquer algorithm recursively breaks down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly. The solutions to the sub-problems are then combined to give a solution to the original problem

*/

// [38, 27, 43, 10] 

//[38,27] and [43,10]


[38] [27] and [43] [10]


// left must be less than or equal to right
#include<iostream>
using namespace std;

void mergeSort(vector<int>&nums,int left,int right){
    int left=0;
    int right=nums.size()-1;

    if(left<=right) return;

    int mid=left+(right - left) / 2;
    //mid =2
    //left side
    mergeSort(nums,left,mid);//
    //test two
    mergeSort(nums,mid+1,right);

}
int main()
{}