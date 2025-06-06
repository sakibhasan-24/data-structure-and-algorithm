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
#include<stack>
using namespace std;
//brute force

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


// // Input:   [4, 5, 2, 10, 8]
// Output:  [5,10,10,-1,-1]

/* 
    optimize it using stack
        ->we will take a stack
        -> stack is empty,so push here input index for the first time i=0;
        ->Now i =1,arr[1]=5 ,Now stack is not empty,stack has now one index which is 0 and also take top
        -> arr[stack.top()"0"] < arr[1];e:g 4<5 which is true,
            ->so we will say hey arr[0]=arr[1];
            ->stack.top will pop
            ->stack.push(1);
        ->Now i=2,arr[2]=2,stack has now index 1,
        ->

*/

vector<int> nextGreaterElements(vector <int> & nums){
    int sizeOfNums=nums.size();
    vector<int> ans(sizeOfNums,-1);
    stack<int>st;
    for(int i=0;i<sizeOfNums;i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
            ans[st.top()]=nums[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main ()


{
    vector<int> nums={4, 5, 2, 10, 8};
    vector <int> res=nextGreaterElements(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}