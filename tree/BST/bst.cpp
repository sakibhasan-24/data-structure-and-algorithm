
#include<iostream>

using namespace std;

// Binary Search Tree is a binary tree in which each node has a value greater than all values in its left subtree and less than all values in its right subtree.
class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to create a binary search tree from a sorted array

/* 
        10
       /  \
      5    15
     / \     \
    3   7     18
         \
          8





          
        10
       /  \
      5    15
     / \     \
    3   7     18
       / \
      6   8
*/

TreeNode* createBST(TreeNode *root,int val){
    TreeNode *node = new TreeNode(val);
    if(root == NULL) {
        return node; // If the tree is empty, return the new node as the root
    }
    TreeNode* current=root;
    while(current!=NULL){
        if(val<current->val){
            //if current->left is NULL, insert the new node here
            if(current->left==NULL){
                current->left=node;
                return root;
            }else {
                current=current->left;
            }
        }else {
            //if current->right is NULL, insert the new node here
            if(current->right==NULL){
                current->right=node;
                return root;
            }else {
                current=current->right;
            }
        }

    }
    return root;

}
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main ()
{
    TreeNode* root = NULL;

    // Insert values
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = createBST(root, val);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}