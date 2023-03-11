//! BINARY SERACH TREES

#include <iostream>
using namespace std;

//*Sturture of TreeNode;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// INSERTION IN BST
TreeNode *insertIntoBst(TreeNode *root, int val)
{
    // base case
    if (root == NULL)
    {
        return new TreeNode(val);
    }

    if (val > root->val)
    {
        root->right = insertIntoBst(root->right, val);
    }

    if (val < root->val)
    {
        root->left = insertIntoBst(root->left, val);
    }

    return root;
}

void takeInput(TreeNode *&root)
{
    cout << "Enter root node value:-";
    int val;
    cin >> val;
    while (val != -1)
    {
        root = insertIntoBst(root, val);
        cout << "Enter Value:";
        cin >> val;
    }
}

int main()
{
    TreeNode *root = NULL;
    takeInput(root);
    return 0;
}
