#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Binary tree is a tree data structure in which each node has at most two children.
// Binary trees are used to represent hierarchical data, such as file systems, organizational structures, and more.
 
class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 


TreeNode *createBinaryTree(){
    int val;
    cin>>val;
    if(val==-1){
        return NULL;
    }
    TreeNode *node = new TreeNode(val);
    cout<<"Enter the left child of "<<val<<": ";
    node->left = createBinaryTree();
    cout<<"Enter the right child of "<<val<<": ";
    node->right = createBinaryTree();
    return node;
}


TreeNode *createBinaryTreeUsingQueue(){
    int val;
    cin>>val;
    if(val==-1) return NULL;
    TreeNode *root=new TreeNode(val);
    queue <*TreeNode> child;
    child.push(root);
    int left,right;
    while(!child.empty()){
        // left.
        TreeNode *temp=child.front();
        child.pop();
        cin>>left;
        if(left!=-1){
            temp->left=new TreeNode(left);
            child.push(temp->left);
        }
        cin>>right;
        if(right!=-1){
            temp->right=new TreeNode(right);
            child.push(temp->right);
        }
        
    }
    return root;

}
int main(){
    TreeNode *root;
    cout<<"Enter the value of the root node: "<<endl;
    root=createBinaryTree();
}
