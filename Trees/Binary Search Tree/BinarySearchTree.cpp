/***************************************
    BINARY SEARCH TREE
    -------------------------------
    Implementation of binary search
    tree along with some helper
    functions.

***************************************/

#include <iostream>

using namespace std;

// Basic structure of node
struct node
{
    int data;
    node* left;
    node* right;
};

// PROTOTYPES
node* create(int x);
node* insert(node* root, int x);
node* remove(node* root, int x);
node* maxValue(node* tree);
node* minValue(node* tree);
void traversal(node* root);


// Creates and returns a new node
node* create(int x)
{
    node* p = new node;
    p->data = x;
    p->left = p->right = NULL;

    return p;
}

// Creates the tree
node* insert(node* root, int x)
{
    if (root == NULL)
        return create(x);
    else if (root->data < x)
        root->right = insert(root->right, x);
    else if (root->data > x)
        root->left = insert(root->left, x);

    return root;
}

// Deletes a node from the tree
node* remove(node* root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    else if(root->data < x)
        root->right = remove(root->right, x);
    else if(root->data > x)
        root->left = remove(root->left, x);
    else{
        if (root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
} 

// Returns the node with the largest value
node* maxValue(node* tree)
{
    node* p = tree;
    while (p && p->right != NULL)
    {
        p = p->right;
    }
    return p;
}

// Returns the node with the smallest value
node* minValue(node* tree)
{
    node* p = tree;
    while(p && p->left != NULL)
        p = p->left;
    
    return p;
}   

// Performs an inorder traversal on tree
void traversal(node* root)
{
    if(root != NULL)
    {
        traversal(root->left);
        cout << root->data << " ";
        traversal(root->right);
    }
}

int main()
{
    // The tree trunk
    node* tree = NULL;
    int n;

    // Inserting values to tree
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int value;
        cout << "Enter " << i+1 << " value :";
        cin >> value;

        tree = insert(tree, value);
    }

    // Displaying tree elements
    traversal(tree);
    cout << endl;

    // Finding the minimum and maximum values
    cout << "Minimum value: " << minValue(tree)->data << endl;
    cout << "Maximum value: " << maxValue(tree)->data << endl;
    cout << endl;

    return 0;
}