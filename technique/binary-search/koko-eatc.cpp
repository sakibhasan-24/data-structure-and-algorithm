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


//koko can not eat eat 0 per hour,must eat at least one
//


int minEatingSpeed(vector<int>& piles, int h) {
    int left=1;
    int right = *max_element(piles.begin(), piles.end());
    int res=right;


    while(left<=right){
        int mid=left+(right-left)/2;
        int totalHours=0;
        for(int i=0;i<piles.size();i++){
            totalHours += ceil((double)piles[i]/mid);
        }
        if(totalHours<=h){
            res = mid;
            right = mid-1;
        }
        else
            left = mid+1;
    }
    return res;

}
