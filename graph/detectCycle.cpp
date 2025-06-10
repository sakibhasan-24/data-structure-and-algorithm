#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Function to detect cycle in a directed graph using Kahn's algorithm
bool detectCycle(int numberOfSteps, vector<vector<int>>& containerStorage) {
    //calculate in degree
    vector<int>indegree(numberOfSteps,0);
    for(int steps=0;steps<numberOfSteps;steps++){
        for(int task=0;task<containerStorage[steps].size();task++){
            indegree[containerStorage[steps][task]]++;
        }
    }

    //first task
    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int count=0;
    //0={1,0}
    while(!q.empty()){
        auto step=q.front();
        q.pop();
        count++;
        for(int next=0;next<containerStorage[step].size();next++){
            int nextStep=containerStorage[step][next];
            indegree[nextStep]--;
            if(indegree[nextStep]==0){
                q.push(nextStep);
            }
        }
    }
    return count != numberOfSteps;
}



int main()


{
    int numberOfSteps = 7;
    vector<vector<int>> containerStorage(numberOfSteps);
    containerStorage[0] = {1, 2};
    containerStorage[1] = {3};
    containerStorage[2] = {3};
    containerStorage[3] = {4};
    containerStorage[4] = {5};
    containerStorage[5] = {0}; // cycle
    containerStorage[6] = {}; 

    if (detectCycle(numberOfSteps, containerStorage)) {
        cout << "There is a cycle in the tasks, cannot complete all tasks." << endl;
    } else {
        cout << "No cycle detected, tasks can be completed." << endl;
    }

    return 0;
}