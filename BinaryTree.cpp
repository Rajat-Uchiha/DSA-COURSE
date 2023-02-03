#include <iostream>
#include <queue>
using namespace std;

//*STRUCTURE OF A NODE FOR B.TREE

class Node
{
    // Data members
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// ! BUILDING TREES

//* FUNCTION TO BUILD A B.TREE USING RECURSION => returns the root node;
Node *build_B_Tree(Node *root)
{
    int val;
    cout << "Enter value ";
    cin >> val;

    root = new Node(val);

    // If we want to stop the insertion then we can insert the value as -1;
    //  Means we do not want to insert value in this subtree/tree anymore;
    if (val == -1)
    {
        return NULL;
    }

    // To insert in left tree;
    cout << "Insertion in left size of " << root->data << endl;
    root->left = build_B_Tree(root->left);

    // To insert in right tree;
    cout << "Insertion in right tree " << root->data << endl;
    root->right = build_B_Tree(root->right);

    return root;
}

// * FUNCTION TO BUILD A B.TREE FROM LEVEL ORDER TRAVERSAL
void build_Level_order(Node *&root)
{
    queue<Node *> q;
    int val;
    cout << "Enter the value for root node: ";
    cin >> val;
    root = new Node(val);
    q.push(root); // Push the first node in the queue

    while (q.empty() == false)
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the value for left node of " << temp->data << ": ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout << "Enter the value for right node of " << temp->data << ": ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

// ! TREE TRAVERSALS

// * LEVEL ORDER TRAVERSAL | BREADTH FIRST SEARCH (USING QUEUE)

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    // First of all we are going to push root because root has no siblings
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
            cout << temp->data << " ";
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

//* INORDER TRAVERSAL ( LEFT ROOT RIGHT )
void inOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//* PREORDER TRAVERSAL (ROOT LEFT RIGHT)
void preOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// * POSTORDER TRAVERSAL (LEFT RIGHT ROOT)
void postOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    // Create a normal node which is NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root = NULL;
    // root = build_B_Tree(root);
    // cout << "Level order traversal " << endl;
    // levelOrderTraversal(root);
    // cout << "Inorder traversal " << endl;
    // inOrder(root);
    // cout << endl;
    // cout << "Preorder traversal " << endl;
    // preOrder(root);
    // cout << endl;
    // cout << "Postorder traversal " << endl;
    // postOrder(root);
    build_Level_order(root);
    levelOrderTraversal(root);
    return 0;
}
