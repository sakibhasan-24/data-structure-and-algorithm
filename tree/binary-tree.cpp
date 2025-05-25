#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
    queue <TreeNode*> child;
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
        void preOrder(TreeNode *root){
            //output 1 2 4 5 3 6
            //1 
            //then store 1 and leave it
            //print it's value
            //then store 2
            //first need to print root,then left then right
            //i insert root then print it...
            if (root==NULL) return;
            stack<TreeNode*>s;
            s.push(root);
            while(!s.empty()){
                TreeNode *node=s.top();
                s.pop();
                cout<<node->val <<" ";
                if(node->right) s.push(node->right);
                if(node->left) s.push(node->left);
            }
        }

        /* 
       1
       / \
      2   3
     / \   \
    4   5   6

        */

        //1 2 3 4 5 6

        void levelOrderTraversal(TreeNode* root){
            if(root==NULL) return;
            queue<TreeNode*>s;
            s.push(root);
            while(!s.empty()){
                TreeNode *node=s.front();
                s.pop();
                cout<<node->val<<" ";
                if(node->left) s.push(node->left);
                if(node->right) s.push(node->right);       
                       
            }
        }


        bool isCCousin(TreeNode *root,int x,int y){
            //same level
            //different parent
              //     1
    //    / \
    //   2   3
    //  /     \
    // 4       5
            if(root==NULL) return false;

            queue<TreeNode*>s;
            s.push(root);
  

    while(!q.empty()){
        int size=q.size();
        TreeNode *parentA=nullptr;
        TreeNode *parentB=nullptr;
        for(int i=0;i<size;i++){
            
             TreeNode *node=q.front();
             q.pop();
             if(node->left){
                if(node->left->val==x){
                    parentA=node;
                }
                if(node->left->val==y){
                    parentB=node;
                }
                q.push(node->left);
             }
             if(node->right){
                if(node->right->val==x){
                    parentA=node;
                }
                if(node->right->val==y){
                    parentB=node;
                }
                q.push(node->right);
             }
             
        }
        if(parentA && parentB){
            return parentA!=parentB;
        }
        if(parentA || parentB) return false;
       
    }
    return false
 }
 vector<int>inOrderMorris(TreeNode *root){
    TreeNode* current=root;
    vector<int>res;
    while(current!=NULL){
        //case-1 current has no left
        if(current->left==NULL){
            res.push_back(current->val);
            current=current->right;
        }
        /*   
        */
        //case-2 current has left
        else { 
            TreeNode* tracker=current->left;
            while(tracker->right!=NULL && tracker->right!=current){
                tracker=tracker->right;
            }
            //case -1=>Not visited yet
            if(tracker->right==NULL){
                tracker->right=current;
                current=current->left;
            }
            //case 2=>already visited
            if(tracker->right==current){
                tracker->right=NULL;
                res.push_back(current->val);
                current=current->right;
            }
        }
    }
    return ans;
 }
int main(){
    TreeNode *root;
    cout<<"Enter the value of the root node: "<<endl;
    root=createBinaryTree();
    preOrder(root);
}
