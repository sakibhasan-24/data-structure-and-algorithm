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


/* 

Activities:  (start, end)
(1, 2)
(3, 4)
(0, 6)
(5, 7)
(8, 9)
(5, 9)


sorted by Sorted by end: (1, 2), (3, 4), (0, 6), (5, 7), (5, 9), (8, 9)

Select (1, 2) → finishes at 2

Next is (3, 4) → starts at 3 ≥ 2 →  Select

Next is (0, 6) → starts at 0 < 4 →  Skip

Next is (5, 7) → starts at 5 ≥ 4 →  Select

Next is (5, 9) → starts at 5 < 7 →  Skip

Next is (8, 9) → starts at 8 ≥ 7 →  Select

 Selected: (1,2), (3,4), (5,7), (8,9) → 4 activities
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    });

    int end = intervals[0][1];
    int count = 1;

    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] >= end){
            count++;
            end = intervals[i][1];
        }
    }

    return intervals.size() - count;  
}
