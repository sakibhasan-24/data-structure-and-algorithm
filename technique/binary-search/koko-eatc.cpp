#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
       
    find the max element in the piles
    int max = *max_element(piles.begin(), piles.end());

    int time=0;
    for(int i=1;i<=max;i++){
        int totalHours=0;
        for(int j=0;j<piles.size();j++){
            totalHours += ceil((double)piles[j]/i);
        }
        if(totalHours<=h){
            time = i;
            break;
        }

    }
    return time;
    
}