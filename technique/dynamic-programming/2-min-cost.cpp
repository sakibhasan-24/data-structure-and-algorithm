#include<iostream>
#include<vector>
using namespace std;



int solve(int n,vector<int>&cost,vector<int>&seen){
    if(n<=1) return n;
    if(seen[n]!=-1) return seen[n];
    return seen[n]=min(cost[n-1]+solve(n-1,cost,seen),cost[n-2]+solve(n-2,cost,seen));
}
int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int>seen(n+1,-1);
    return solve(n,cost,seen);
        
}

int  main()


