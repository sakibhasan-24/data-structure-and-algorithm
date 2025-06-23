#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

 int findDuplicate(vector<int>& nums) {
     unordered_map<int,int>map;
     for(int i=0;i<nums.size();i++){
        int num=nums[i];
        if(map.count(num)){
            return nums[i];
        }else {
            map[nums[i]]++;
        }
     }
     return 0;   



    }


//   [1,3,4,2,2]
//slow=0
//fast=0

int findDuplicate(vector<int>& nums) {
    int slow=nums[0];
    int fast=nums[0];
    //slow=1,fast=1
    //slow=3,fast=nums[nums[fast]]=>nums[fast]=nums[1]=3,nums[3]=2
    //slow=2,fast=nums[nums[fast]]=>nums[fast]=nums[2]=4,nums[4]=2
    //now slow and fast are same,

    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while(slow!=fast);
    slow=nums[0];
    while(slow!=fast){
        // [1,3,4,2,2]
        //slow=3,fast=
        slow=nums[slow];
        fast=nums[fast];
    }
    return nums[slow];
}
int main()


{

}