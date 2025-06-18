#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
Node* cloneGraph(Node* node){
    unordered_map<Node*,Node*>visited;
    if(!node) return nullptr;
    if(visited.count(node)) return visited[node];

    //create a new node
    Node* newNode=new Node(node->val);
    queue<Node*>q;
   
    visited[node]=newNode;
    q.push(node);

    while(!q.empty()){
        Node* top=q.top();
        q.pop();
       for(int i=0;i<top->neighbours.size();i++){
            Node *neigh=top->neighbour[i];
            if(!visited.count(neigh)){
                visited[neigh]=new Node(neigh->val);
                q.push(neigh);
            }
            visited[top]->neighbours.push_back(visited[neigh]);
       }
       

    }
    return visited[node];
}
int main ()


{

}