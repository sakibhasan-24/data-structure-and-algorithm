#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
   
    priority_queue<int> maxHeap;

 
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
   
    void addNum(int num) {
        
        maxHeap.push(num);

    
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

  
    double findMedian() {
      
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

      
        return maxHeap.top();
    
};


int main() {
    MedianFinder mf;

    vector<int> nums = {5, 2, 7, 1, 3};
    for (int num : nums) {
        mf.addNum(num);
        cout << "Inserted: " << num << ", Current Median: " << mf.findMedian() << endl;
    }

    return 0;
}
