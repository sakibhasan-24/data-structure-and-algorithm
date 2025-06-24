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
    return -1;
}
int main ()


{

}