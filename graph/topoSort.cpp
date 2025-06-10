#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Must directed acyclic graph (DAG) for topological sort
// u -> v means u comes before v in the topological order

//E:G task A must be completed before task B


//rules are simple: "Must be done before" rule
/* 
What’s in-degree?
Number of edges coming into a node.

Are there multiple valid topological orderings?
Yes, as long as they respect the constraints.
    


*/



//Let's design a cooking recipe as a directed acyclic graph (DAG) using topological sort

      /* 
        Todo:
            1)number of steps need 6 
            2)step 0: Prepare ingredients
            3)step 1: Chop vegetables
            4)step 2: Boil water
            5)step 3: Cook vegetables
            6)step 4: Add spices
            7)step 5: Serve dish
            
        "Must be done before" rule
            8)step 0 must be done before step 1
            9)step 0 must be done before step 2
            10)step 1 must be done before step 3
            11)step 2 must be done before step 3
            12)step 3 must be done before step 4
            13)step 4 must be done before step 5
         
        for their storage and retrieval we need a vector of vectors
        14)vector<vector<int>> adjList(6);
            adjList[0] = {1, 2}; // step 0 must be done before step 1 and step 2
            adjList[1] = {3};    // step 1 must be done before step 3
            adjList[2] = {3};    // step 2 must be done before step 3
            adjList[3] = {4};    // step 3 must be done before step 4
            adjList[4] = {5};    // step 4 must be done before step 5


        we need to find which step can be done first
        assign all pendings task is 0

      
      */


      int main ()


      {
        int numberOfSteps = 6;
        vector<vector<int>> containerStorage(numberOfSteps);
        containerStorage[0] = {1, 2}; 
        containerStorage[1] = {3};
        containerStorage[2] = {3};
        containerStorage[3] = {4};
        containerStorage[4] = {5};
        vector<int>pendingSteps(numberOfSteps, 0);

        
        // Calculate in-degree/pending steps
        //i need to find for 0 how mane tasks are pending
        //for 1 how many tasks are pending
        // for 2 how many tasks are pending
        for(int steps=0;steps<numberOfSteps;steps++){
            for(int task=0;task<containerStorage[steps].size();task++){
                //containerStorage[0].size()=2
                //next steps=containerStorage[0][task]=1
                // pendingSteps[1]++;
                int nextStep=containerStorage[steps][task];
                pendingSteps[nextStep]++;
            }
        }

        // Now we can use a queue to process the steps
        //those steps which have no pending tasks can be done first
        queue<int>readyToDo;
        for(int i=0;i<numberOfSteps;i++){
            if(pendingSteps[i]==0){
                readyToDo.push(i);
            }
        }
        vector<int>cookingOrder;
        while(!readyToDo.empty()){
            int currentStep=readyToDo.front();//in this case it is 0 and it is prepare ingredients
            readyToDo.pop();
            cookingOrder.push_back(currentStep);
            // Process the current step and reduce the in-degree of its neighbors
            //find the next steps which are dependent on current step
            for(int nextStep=0;nextStep<containerStorage[currentStep].size();nextStep++){
                int currentTaskDependent =containerStorage[currentStep][nextStep];
                pendingSteps[currentTaskDependent]--;
                if(pendingSteps[currentTaskDependent] == 0) {
                    readyToDo.push(currentTaskDependent);
                }
            }
        }

        // Print the cooking order
        cout << "Cooking order: ";
        for(int step : cookingOrder) {
            cout << step << " ";
        }
    
      }