// what is NGE

// For each element, we need to find the next element on the right that is greater than the current element.
// Input:   [4, 5, 2, 10, 8]
// Output:  [5,10,10,-1,-1]

// For 4 → next greater is 5

// For 5 → next greater is 10

// For 2 → next greater is 10

// For 10 → no greater → -1

// For 8 → no greater → -1


#include<iostream>
#include<vector>
using namespace std;
vector <int> nge(vector<int> &nums){
    vector<int> ans(nums.size(),-1);
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                ans[i]=nums[j];
                break;
            }
        }
    }
    return ans;
}


int main ()


{
    vector<int> nums={4, 5, 2, 10, 8};
    vector <int> res=nge(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}