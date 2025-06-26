#include<iostream>
#include<vector>
#include<algorithm>


vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //a+b+c+d=target
        //duplicate not allow
        Example 1:

        Input: nums = [1,0,-1,0,-2,2], target = 0
        Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
        Example 2:

        Input: nums = [2,2,2,2,2], target = 8
        Output: [[2,2,2,2]]

}



vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> result;  
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int k = j + 1; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        sort(quad.begin(), quad.end()); 
                        result.insert(quad);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(result.begin(), result.end());
}

// 

Input: nums = [2,2,2,2,2], target = 8
        Output: [[2,2,2,2]]


       i need to find those element who can create my 8...
       i need to add 4 element
       it can be and must  be [2,2,2,2]
       sort //2 2 2  2



       vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // a+b+c+d=target
        // duplicate not allow

       
        vector<vector<int>> res;
         if (nums.size() < 4)  return res;
           
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                 if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1;
                int r = nums.size() - 1;

                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                       res.push_back({nums[i], nums[j], nums[l], nums[r]});

                        l++;
                        r--;
                        // duplicate check
                        while (l<r && nums[l] == nums[l - 1]) {
                            l++;
                        }
                        while (l<r && nums[r] == nums[r + 1]) {
                        r--;
                        }
                    } else if (sum > target) {

                        r--;
                    } else {
                        l++;
                    }
                }
               
            }
        }
        return res;
    }