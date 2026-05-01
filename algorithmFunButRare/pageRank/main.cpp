#include<iostream>
#include<vector>


using namespace std;
int findMajority(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    //  Find candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    //  Verify candidate
    int actualCount = 0;
    for (int num : nums) {
        if (num == candidate) {
            actualCount++;
        }
    }

    if (actualCount > nums.size() / 2) {
        return candidate;
    }

    return -1;
}
// this is Boyer -more majority algorithm


int main()
{
    vector<int> nums = {3,2};// 3 appears 4 times, 4 appears 2 times, 2 appears 1 time
    int result = findMajority(nums);
    
    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "No majority element exists." << endl;
    }

    return 0;
}