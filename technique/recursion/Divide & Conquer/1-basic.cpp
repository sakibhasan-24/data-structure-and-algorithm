/* 
divide and conquer is an algorithm design paradigm. A divide-and-conquer algorithm recursively breaks down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly. The solutions to the sub-problems are then combined to give a solution to the original problem

*/

// [38, 27, 43, 10] 

//[38,27] and [43,10]


// [38] [27] and [43] [10]


// left must be less than or equal to right
#include<iostream>
#include<vector>
using namespace std;



void merge(vector<int>&nums,int left,int right,int mid){
    int l=left;
    int r=mid+1;
    vector<int>temp;
    while(l<=mid && r<=right){
        if(nums[l]<nums[r]) temp.push_back(nums[l++]);
        else temp.push_back(nums[r++]);
    }

    //they are not empty yet

    while(l<=mid){
        temp.push_back(nums[l++]);
    }
     while(r<=right){
        temp.push_back(nums[r++]);
    }
    //copy in orginal array

    for(int i=left;i<=right;i++){
        nums[i]=temp[i-left];
    }
}
void mergeSort(vector<int>&nums,int left,int right){
    if(left>=right) return;
    int mid=left+(right - left) / 2;
    mergeSort(nums,left,mid);
    mergeSort(nums,mid+1,right);
    // cout<<"We will Merge Now"<<endl;
    merge(nums,left,right,mid);
}

void printArr(vector<int>&nums,int index){
      if (index == nums.size()) return;
      cout<<nums[index]<<endl;
      printArr(nums,index+1);
      cout<<"We are end now "<<nums[index]<<endl;
      
}
int main()
{
    // vector<int>nums={1,2,3,4,5,6,7};
    // printArr(nums,0);
    vector<int> nums = {4, 2, 1, 3};
    mergeSort(nums, 0, nums.size() - 1);  
    
    for (int num : nums) {
        cout << num << " ";
    }
}