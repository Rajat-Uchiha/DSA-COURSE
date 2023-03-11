//! BINARY SERACH TREES

#include <bits/stdc++.h>
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

// Find minimum;
int findMini(TreeNode *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root->val;
}

void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;

    // First of all we are going to push root because root has no siblings
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->val << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

// DELETION IN BST
TreeNode *deleteFromBST(TreeNode *root, int val)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        //* 0 child
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }

        //* 1 child
        //* left child
        if (root->left != NULL && root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        //* right child
        if (root->right != NULL && root->left == NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }

        //* 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = findMini(root);
            root->val = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    if (root->val < val)
    {
        root->right = deleteFromBST(root->right, val);
    }
    else
    {
        root->left = deleteFromBST(root->left, val);
    }
    return root;
}

int main()
{
    TreeNode *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    root = deleteFromBST(root, 5);
    cout << "AFTER DELETION" << endl;
    levelOrderTraversal(root);
    return 0;
}
