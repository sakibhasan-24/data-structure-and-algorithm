// #include<iostream>
// using namespace std;

// int main(){
//     int arr[5] = {1,2,3,4,5};
//     cout<<arr[0]<<endl;
//     cout<<arr[1]<<endl;
//     cout<<arr[2]<<endl;
//     cout<<arr[3]<<endl;
//     cout<<arr[4]<<endl;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Result {
    int alice_idx;
    int bob_idx;
    int min_gap;
};

Result solveSmartScheduler(vector<int>& pods, int energy_limit) {
    // we will follow two pointers approach
    int alice_idx = 0;
    int bob_idx = pods.size() - 1;
    int min_gap = INT_MAX;

    while (alice_idx < bob_idx) {
        int alice_energy = pods[alice_idx];
        int bob_energy = pods[bob_idx];
        int gap = abs(alice_energy - bob_energy);

        if (gap <= energy_limit) {
            min_gap = min(min_gap, gap);
            alice_idx++;
            bob_idx--;
        }
    }
}

int main() {
   
    vector<int> pods = {0, 15, 30, 45, 60, 75, 90};
    int energy_limit = 40; 
    Result r = solveSmartScheduler(pods, energy_limit);
    return 0;
}