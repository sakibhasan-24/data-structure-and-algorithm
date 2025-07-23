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