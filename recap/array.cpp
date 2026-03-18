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
    
}

int main() {
    // Distances of pods from start: 0, 10, 20, 30, 40, 50, 60
    vector<int> pods = {0, 15, 30, 45, 60, 75, 90};
    int energy_limit = 40; 
    Result r = solveSmartScheduler(pods, energy_limit);
    return 0;
}