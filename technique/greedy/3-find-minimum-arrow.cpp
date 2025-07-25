#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

//we can convert is as lambda
bool compare(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size() == 0) return 0;
    sort(points.begin(), points.end(), compare);
    int arrows = 1;
    int end = points[0][1];

    for(int i = 1; i < points.size(); i++) {
        if(points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }
    return arrows;
}