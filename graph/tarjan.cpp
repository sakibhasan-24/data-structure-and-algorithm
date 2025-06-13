// 🗺️ Map of cities and roads (the graph)
//⏳ A clock — to mark the time a city was first visited (disc[])
//🧾 A magic notebook — records the lowest discovery time reachable from any city (low[])
// 🧺 A basket (stack) — to carry cities he's still exploring

// 🧵 A thread tied to each city in the basket, so he knows it's still under investigation (onStack[])




/* 


Step

    1)discovery
    2)explore
    3)find the neighbour
    4)
*/
#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>>tarjans(int V,vector<int>adj[]){
    vector<vector<int>>ans;
    vector<int>disc(V);
    vector<int>low(V);
    vector<bool>visited(V,false);
    stack<int>s;
    vector<bool>inStack(V,false);
    int timer=0;

}

int main()


{

}