#include<iostream>
#include<vector>


using namespace std;
int findMajority(vector<int>& nums) {
    int couunt=0;
    int candidate = 0;
    for (int num : nums) {
        if (couunt == 0) {
            candidate = num;
        }
        couunt += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main()
{
    vector<int> nums = {3, 3, 4, 2, 3, 3, 1,1,1,1,1,1};// 3 appears 4 times, 4 appears 2 times, 2 appears 1 time
    int result = findMajority(nums);
    
    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "No majority element exists." << endl;
    }

    return 0;
}