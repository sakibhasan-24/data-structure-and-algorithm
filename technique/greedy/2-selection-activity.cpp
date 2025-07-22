#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Greedy algorithm to select maximum number of activities
// that don't overlap

// Activity is represented by a pair of start and end time
// Activities are sorted by end time

// Time Complexity: O(nlogn)
// Space Complexity: O(1)

struct Activity {
    int start;
    int end;
}