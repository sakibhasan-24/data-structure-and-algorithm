class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int main ()
{
    TreeNode *root = new TreeNode(1);
    root->left=new Treenode(2);
    root->right=new TreeNode(3);
    return 0;
}