#include<iostream>
#include<vector>
#include <iomanip>


using namespace std;
// what is pageRank

/* 
The PageRank algorithm calculates the importance of nodes in a directed 
graph by iteratively distributing "rank" from one node to its neighbors
*/

// make efficient
// function to calculate pageRank




void pageRank(vector<vector<int>> &adj, int N, int iterations=100, double d=0.85){
    vector<double> rank(N, 1.0/N);
    vector<double> newRank(N, 0.0);

    for(int i=0; i<iterations; i++){
        for(int j=0; j<N; j++){
            newRank[j] = (1.0 - d) / N;
        }

        for(int k=0; k<N; k++){
            int outdegree = adj[k].size();

            if(outdegree == 0){
                // handle dangling node
                for(int j=0; j<N; j++){
                    newRank[j] += d * (rank[k] / N);
                }
            } else {
                for(int neighbor : adj[k]){
                    newRank[neighbor] += d * (rank[k] / outdegree);
                }
            }
        }

        rank = newRank;
    }

    cout << fixed << setprecision(4);
    for(int i=0; i<N; i++){
        cout << "Page " << i << " Rank: " << rank[i] << endl;
    }
}

int main(){
    int N = 4;
    vector<vector<int>> adj(N);

    adj[0] = {1, 2};
    adj[1] = {2};
    adj[2] = {0};
    adj[3] = {2};

    pageRank(adj, N);
}