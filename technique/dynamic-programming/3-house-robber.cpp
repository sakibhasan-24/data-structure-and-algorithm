#include <iostream>
#include<stack>
using namespace std;
/* i can not rob two adjacent houses.
so option is ,i can rob it or skip it, */
// nums = [1,2,3,1]
int solve(int n,vector<int>&nums,vector<int>&memo){
    if(n==0) return 0;
    if(n==1) return nums[0];
    if(memo[n]!=-1) return memo[n];
    //rob
    int rob=nums[n-1]+solve(n-2,nums,memo);

    //skip
    int skip=solve(n-1,nums,memo);

    //return max and call again
    return memo[n]=max(rob,skip);
} 
 int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>memo(n+1,-1);
        return solve(n,nums,memo);
    }

int main()


{
 cout<<"check"<<endl;

}