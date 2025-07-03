Backtracking = Recursion + Choices + Undoing
1)choose something
2)recursively solve for the rest
3)undo the choice
4)try next One


/* 
--------REAL LIFE---------------

    1-> have blue shirt,red shirt,white shirt,jeans,formal.
    2->wear it,if not fit then pop it and wear a new one

*/






#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

//1 2 
void solve(vector<int>& nums,int index,vector<int>& cur,vector<vector<int>>& res){
        if(index==nums.size()){
            res.push_back(cur);
            return;
        }
        //now index is 0 and size=2
        cur.push_back(nums[index]);
        solve(nums,index+1,cur,res);//([1,2,3],1,[1],[]);//([1,2,3],2,[1,2],[]); //([1,2,3],2,[1,2,3],[]);
        cur.pop_back();
        solve(nums,index+1,cur,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<vector<int>>res;
     vector<int>cur;
     solve(nums,0,cur,res);
     return res;   
    }

int main() {
    vector<int> nums = {1, 2};
    vector<vector<int>> allSubsets = subsets(nums);

    for (auto& subset : allSubsets) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
