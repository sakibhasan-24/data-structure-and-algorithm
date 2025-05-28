
#include<iostream>
#include<algorithm>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;
    TreeNode(int x) : val(x), left(NULL), right(NULL), height(1) {}
};

int getHeight(TreeNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(TreeNode* node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}


TreeNode* leftRotate(TreeNode* root){
    TreeNode* newRoot=root->right;
    TreeNode* temp=newRoot->left;
    newRoot->left=root;
    root->right=temp;
    //update height
    root->height=1+max(getHeight(root->left), getHeight(root->right));
    newRoot->height=1+max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

TreeNode* rightRotate(TreeNode* root){
    TreeNode* newRoot=root->left;
    TreeNode* temp=newRoot->right;
    newRoot->right=root;
    newRoot->left=temp;
    root->height=1+max(getHeight(root->left), getHeight(root->right));
    newRoot->height=1+max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;

}
TreeNode* insert(TreeNode* root,int val){
    if(root==NULL) {
        return new TreeNode(val);
    }
    //value is less than root, go to left subtree
    if(val<root->val){
        root->left = insert(root->left, val);
    }
    //value is greater than root, go to right subtree
    else if(val>root->val){
        root->right = insert(root->right, val);
    } else {
        return root;
    }
    //we need to update the height of the ancestor node
    root->height=1+max(getHeight(root->left), getHeight(root->right));

    //get balance factor for ancestor node
    int balance = getBalance(root);
    //if <-1 it is right heavy
    if(balance <-1 && val>root->right->val){
        //we need to left rotate
        return    leftRotate(root);
     }
    //if >1 it is left heavy
    if(balance >1 && val<root->left->val){
        //we need to right rotate
        return rightRotate(root);
    }
    if(balance >1 && val>root->left->val){
        //we need to left right rotate
        root->left=rightRotate(root->left);
        return leftRotate(root);
    }
    if(balance <-1 && val<root->right->val){
        //we need to right left rotate
        root->right=leftRotate(root->right);
        return rightRotate(root);
    }
    return root;

}
int main()


{
TreeNode* root=NULL;
root=insert(root, 10);
root=insert(root, 5);
root=insert(root, 15);
root=insert(root, 3);
root=insert(root, 7);

}