#include<iostream>
#include<vector>
using namespace std;

Input: nums = [1,1,1], k = 3
Output: 1

/* 
    how many 2 can we produce form this vector
    index[0]+index[1]=2//count=1
    index[1]+index[2]=2//count=2



*/
int subarraySum(vector<int>& nums, int k) {
    int size = nums.size();
    int count = 0;

    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < size; j++) {
            sum += nums[j];
            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

//make it more optimize
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    int count = 0, sum = 0;
    //[10,20,30] k=30
    prefixCount[0] = 1;//{0:1}
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];//0+=10=10,sum is 10 now
        //we have to check does 10 already in map or not
        //how we get it sum-k;10-30=-20
        if(prefixCount.count(sum-k)){
            //if exists then we have to add it to count
           count+=prefixCount[sum-k];//count=0,prefixCount[-20]=0
        }
        //Now we have to add sum to map
        prefixCount[sum]++;
    }
    return count;
}

int main ()


{
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>>n;
    vector<int>res(n);
    cout<<"Enter the array elements "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    //prefix sum
    vector<int>prefix(n);
    prefix[0]=res[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+res[i];
    }
    //[10,20,30,40,50]
    cout<<"the Prefix sum is "<<endl;
    for(int i=0;i<n;i++){
        cout<<prefix[i]<<" ";
    }
}