#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
double maxProbability
    (int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
    {
        //need to create an adjacancy list
        int rows=edges.size();
        int cols=edges[0].size();
        //bellman ford don't need adj.
        unordered_map<int, vector<pair<int, double>>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double w=succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
/* 
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths
 from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

*/
        vector<double>maxPro(n,0.00);
       maxPro[start_node]=1.00;
       for(int i=0;i<n-1;i++){
        for(int j=0;j<edges.size();j++){
            double u=edges[j][0];
            double v=edges[j][1];
            double p=succProb[j];

            if(maxPro[v]<maxPro[u]*p){
                maxPro[v]=maxPro[u]*p;
            }
            if(maxPro[u]<maxPro[u]*p){
                maxPro[u]=maxPro[u]*p;
            }
        }
       }

       return maxPro[end_node];

    }



int main ()


{
    
}