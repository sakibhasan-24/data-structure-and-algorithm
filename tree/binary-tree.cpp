#include<iostream>
#include<vector>
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
int main(){
    TreeNode *root;
    cout<<"Enter the value of the root node: "<<endl;
    int val;
    cin>>val;
    root=createBinaryTree();
}