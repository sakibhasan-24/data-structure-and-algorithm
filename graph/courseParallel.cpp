#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    // create an adj list
    //run top
        //
    // find lowest time
    int minTime=0;
    vector<vector<int>>adj(n);
    vector<int>indegree(n,0);
    for(int i=0;i<relations.size();i++){
    int u = relations[i][0] - 1; 
    int v = relations[i][1] - 1;
    adj[u].push_back(v);       
    indegree[v]++;
    }
    queue<int>readyToStart;
    vector<int>completeTime;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            readyToStart.push(i);
            completeTime[i]=time[i];
        }
    }
    
    //relax edges
    int maxTime=0;
    while(!readyToStart.empty()){
        int current=readyToStart.front();
        readyToStart.pop();
        for(int v=0;v<adj[current].size();v++){
        completeTime[v]=max(completeTime[v],completeTime[current]+time[v]);
        indegree[v]--;
        if(indegree[v]==0){
            readyToStart.push(v);
        }

        }
    }
     return *max_element(completeTime.begin(), completeTime.end());

}


int main()


{
     int n = 5;
    vector<vector<int>> relations = {{1,5},{2,5},{3,5},{3,4},{4,5}};
    vector<int> time = {1,2,3,4,5};
    cout << minimumTime(n, relations, time) << endl;

}