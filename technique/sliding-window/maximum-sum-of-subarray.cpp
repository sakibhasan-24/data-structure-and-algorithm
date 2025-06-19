/* Input  : arr[] = {100, 200, 300, 400}, k = 2
Output : 700
1=100+200 =300
2=200+300=500
3=300+400=700
//max 700
4-2=2
We get maximum sum by considering the subarray [300, 400]
9-4=5
Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}, k = 4 
1)1+4+2+10=17
2)4+2+10+23=39
3)2+10+23+3=38
4)10+23+3+1=37
5)23+3+1+0=27
6)3+1+0+20=24
Output : 39 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;
//O(n * k)
int maximumOutput(vector<int>&nums,int k){
    int max_sum = INT_MIN;
    cout<<"Nums.size()-k = "<<nums.size()-k<<endl;
    for(int i=0;i<=nums.size()-k;i++){
        int curSum=0;
        for(int  j=0;j<k;j++){
            curSum+=nums[i+j];
        }
        max_sum=max(max_sum,curSum);
        
    }
    return max_sum;
}

//  Input  : arr[] = {100, 200, 300, 400}, k = 2
// Output : 700

// window technique:first two sum is =300

int slidingWindowSum(vector<int>&nums,int k){
    int sum=0;
    int maxSum=sum;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    //  arr[] = {100, 200, 300, 400}, k = 2
    for(int i=k;i<nums.size();i++){
       sum = sum + nums[i] - nums[i - k];
        maxSum=max(sum,maxSum);
    }
    return maxSum;
    
}
bool isValid(vector<int>&nums,int starting,int k){
    int l=starting;
    int r=starting+k-1;
    unordered_set<int> visited;
    while(l<=r){
        if(visited.count(nums[l])){
            return false;
        }
            visited.insert(nums[l]);
            l++;
        
    }
    return true;
    
}

    //  [1,5,4,2,9,9,9], k = 3
long long maximumSubarraySum(vector<int>& nums, int k) {
    long long sum=0;
    long long maxSum=0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    if(isValid(nums,0,k)) {
        maxSum=sum;
    }
    for(int i=k;i<nums.size();i++){
        sum=sum+nums[i]-nums[i-k];
        if(isValid(nums,i-k+1,k)){
            maxSum=max(sum,maxSum);
        }
    }
    return maxSum;
        
    }



    //optimize 
    //  vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    1:1=>1
    long long maximumSubarraySum(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        long long sum=0;
        long long maxSum=0;
        int left=0;
        for(int r=0;r<nums.size();r++){
            int num=nums[r];
            mp[num]++;
            sum+=num;


            if(r-left+1>k){
                int leftNum=mp[left];
                mp[leftNum]--;
                sum-=leftNum;
                if(mp[leftNum]==0){
                    mp.erase(leftNum);
                }
                 left++;
            }
            if(r-left+1==k && mp.size()==k){
                 maxSum = max(maxSum, sum);
            }


        }
        return maxSum;
    }

int main ()


{
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;

    cout << slidingWindowSum(arr, k) << endl;
}