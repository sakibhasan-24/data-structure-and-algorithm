#include <bits/stdc++.h>


using namespace std;

void solve(vector<int>& nums, int index, vector<vector<int>>& ans,vector<int>& currentAssign,vector<bool>&visited){
    if(index == nums.size()){
        ans.push_back(currentAssign);
        return;
    }
    for(int i=0;i<nums.size();i++){
        //if already visited skip it
        if(visited[i]) continue;
        //if not visited then mark it as visited and assign it to current index
        visited[i] = true;
       currentAssign.push_back(nums[i]);
        //now call the function for next index
        solve(nums,index+1,ans,currentAssign,visited);
        //now unmark it as visited and unassign it from current index
        visited[i] = false;

    }
}
vector<vector<int>> permute(vector<int>& nums) {
    //[1,2,3]

    //pick 1,then 2 and then 3...
    // here three people standing,i need to re arrange them all possible unique way.
    //it could be 123,132,213,231,312,321
    //so we need to generate all possible unique way to arrange them.
    //so we need to use backtracking to solve this problem.
    /* 
        hey 1,please stand here,you are not visited yet
        let's next index,hey 2 stand.
        next,hey 3 stand.
    
    */

    vector<vector<int>> ans;
    vector<bool>visited(nums.size(),false);
    vector<int>currentAssign;
    solve(nums,0,ans,currentAssign,visited);
    return ans;
        
    }
