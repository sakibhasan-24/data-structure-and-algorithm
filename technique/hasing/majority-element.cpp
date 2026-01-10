#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

//brute force
int majorityElement(vector<int>& nums){
    int max=0;
    int count=0;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            if(nums[i]==nums[j] && i!=j){
                count++;
            }
        }
        if(count>nums.size()/2){
        return nums[i];
    }
    }
    return -1;
}
//better 

int majorityElement(vector<int>&nums){
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        int key=nums[i];
        mp[key]++;
        // {1,2,3,2,2}
        //{1:1,2:3,3:1}
        if(mp[key]>nums.size()/2){
            return key;
        }
    }
    return;
}

// Initialize an element m and a counter c with c = 0
// For each element x of the input sequence:
// If c = 0, then assign m = x and c = 1
// else if m = x, then assign c = c + 1
// else assign c = c − 1
// Return m
//   // {1,2,3,2,2}
//   m,c=0
//   for i=0  c==0 them m=1,c=1;
//   for i=1, m(1)=x(2) c=c+1=2
// Boyer-Moore algo
  int majorityElement(vector<int>&nums){
    int c=0,m=0;
    for(int x=0;x<nums.size();x++){
        if(c==0){
            m=nums[x];
            c=1;
        }
        else if(m==nums[x]){
            c=c+1;
        }else {
            c=c-1;
        }
    }
    return m;
  }
int main ()


{



    return 0;


}


// {1,2,3,2,2}
// {1:1,2:3,3:1}
// {1,2,3,2,2}
// {1:1,2:3,3:1}