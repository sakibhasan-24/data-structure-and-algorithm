/* 
What is Greedy Algorithm?
always makes the choice that seems to be the best at that moment.

The	two	basic	properties	of	optimal	Greedy	algorithms	are:
 1)Greedy	choice	property
 2)Optimal	substructure


*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minMergeCost(vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Step 1: Push all file sizes into the min-heap
    for (int size : files) {
        minHeap.push(size);
    }

    int totalCost = 0;

    // Step 2: Keep merging until one file remains
    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int mergeCost = first + second;
        totalCost += mergeCost;

        minHeap.push(mergeCost);
    }

    return totalCost;
}

int main() {
    vector<int> files = {5, 2, 4, 3};
    int result = minMergeCost(files);
    cout << "Minimum total cost to merge files: " << result << endl;
    return 0;
}