#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;





// Order to complete semester tasks:
// 0 Enroll in courses
// 1 Attend lectures
// 2 Study materials
// 3 Do assignments
// 4 Prepare for exams
// 5 Take final exams
// 6 Apply for internships

int main()
{
    int numberOfSteps=7;
    string steps[] = {
        "Enroll in courses",
        "Attend lectures",
        "Study materials",
        "Do assignments",
        "Prepare for exams",
        "Take final exams",
        "Apply for internships"
    };
    vector<vector<int>> containerStorage(numberOfSteps);
    containerStorage[0] = {1, 2}; // step 0 must be done before step 1 and step 2
    containerStorage[1] = {3};    // step 1 must be done before step 3
    containerStorage[2] = {3};    
    containerStorage[3] = {4};    
    containerStorage[4] = {5};
    containerStorage[5] = {6};   
    vector<int> pendingSteps(numberOfSteps, 0);
    //need to find first task which can be done first
    for(int steps=0;steps<numberOfSteps;steps++){
        for(int task=0;task<containerStorage[steps].size();task++){
            pendingSteps[containerStorage[steps][task]]++;
        }
    }
    //find who is 0 dependency
    queue<pair<int,string>> readyToDo;
    for(int task=0;task<numberOfSteps;task++){
        if(pendingSteps[task]==0){
            readyToDo.push({task, steps[task]});
        }
    }
    //if there pending task has no 0 that means we have a cycle
    if(readyToDo.empty()){
        cout << "There is a cycle in the tasks, cannot complete all tasks." << endl;
        return 0;
    }
    vector<pair<int,string>> courseSerial;//for printing
    
    while (!readyToDo.empty())
    {
        
        auto [task, stepText] = readyToDo.front();
        readyToDo.pop();
        //0={1,2};
        courseSerial.push_back({task, stepText});
        for(int nextTask=0;nextTask<containerStorage[task].size();nextTask++){
            int nextProcess=containerStorage[task][nextTask];
            pendingSteps[nextProcess]--;
            if(pendingSteps[nextProcess]==0){
                readyToDo.push({nextProcess,steps[nextProcess]});
            }
        }   
        
    
    }

    //print all task with number and steps

    cout<<"Here Is Next Semester Course Outline"<<endl;
    for(int i=0;i<courseSerial.size();i++){
        auto[task,step]=courseSerial[i];
        cout<<" task[ "<<task<<" ]"<<" is : "<<step<<endl;
    }
    
}