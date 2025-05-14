#include<iostream >
#include<vector>
#include<string>
#include<Windows.h>
using namespace std;



class NaryTreeNode {
    public:
        string  val;
        vector<NaryTreeNode*> children;

        NaryTreeNode(string _val) : val(_val) {}
};

// N-ary tree is a tree data structure in which each node can have at most n children.
// N-ary trees are used to represent hierarchical data, such as file systems, organizational structures, and more.



void printTree(NaryTreeNode* root, string indent = "", bool isLast = true) {
    if (!root) return;

    // Print the current node
    cout << indent;
    if (isLast) {
        // Last child
        // Print the last child with a different indent
        cout << "└── ";
        // Add an extra space for the last child
        // to make the tree look better
        indent += "    ";
    } else {
        // Not the last child
        cout << "├── ";
        // Add an extra space for the not last child
        indent += "│   ";
    }
    cout << root->val << endl;

    for (size_t i = 0; i < root->children.size(); ++i) {
        printTree(root->children[i], indent, i == root->children.size() - 1);
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8); 
    NaryTreeNode *root = new NaryTreeNode("Data-structure");
    NaryTreeNode *child1 = new NaryTreeNode("Array");
    NaryTreeNode *child2 = new NaryTreeNode("Linked List");
    NaryTreeNode *child3 = new NaryTreeNode("Stack");
    NaryTreeNode *child4 = new NaryTreeNode("Queue");
    NaryTreeNode *child5 = new NaryTreeNode("Tree");
    root->children={child1, child2, child3, child4, child5};
    NaryTreeNode *child6 = new NaryTreeNode("Binary Tree");
    NaryTreeNode *child7 = new NaryTreeNode("Binary Search Tree");
    NaryTreeNode *child8 = new NaryTreeNode("AVL Tree");
    NaryTreeNode *child9 = new NaryTreeNode("Red Black Tree");
    child5->children={child6, child7, child8, child9};
    printTree(root);
    return 0;
}