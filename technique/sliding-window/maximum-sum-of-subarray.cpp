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
                
int main ()


{
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;

    cout << slidingWindowSum(arr, k) << endl;
}