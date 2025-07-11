
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


TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q) {
    if (root == NULL) return NULL;
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}


/* 

         10
       /  \
      5    15
     / \     \
    3   7     18
       / \
      6   8

*/
bool isExist(TreeNode*root,int target){
    if(root==NULL) return false;
    if(root->val==target) return true;

    TreeNode* current=root;
    while(current){
        if(current->val==target) return true;
        if(target<current->val){
            //left side
            if(current->left==NULL){
                return false;
            }else {
                current=current->left;
            }
        }else {
            if(current->right==NULL){
                return false;
            }else {
                current=current->right;
            }
        }
    }
    return false;
}
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
/*
       10
       /  \
      5    15
     / \     \
    3   7     18
       / \
      6   8
*/


TreeNode* deleteBST(TreeNode* root,int target){
    if(root==NULL) return NULL;
    // if(!isExist(target)) return ;
    //delete leaf node
        if(root->val==target){
            if(root->left==NULL && root->right==NULL) {
                delete root; 
                return NULL; 
            }
            if(root->left==NULL){
                 TreeNode* temp=root->right;
                delete root;
                return temp;
               
            }
            if(root->righ==NULL){
                 TreeNode* temp=root->left;
                delete root;
                return temp;
               
            }
            //node with two children
            TreeNode* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left; 
            }
            TreeNode* temp=successor;
            root->val=successor->val;
           root->right=deleteBST(root->left,target);
           return root;


        }
        if(target<root->val){
            root->left=deleteBST(root->left,target);
        }
        if(target>root->val){
            root->right=deleteBST(root->right,target);
        }
        return root;

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
    cout<<isExist(root,80)<<endl;

    return 0;
}