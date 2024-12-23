#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    int height;
};

node* create(int x) {
    node* p = new node;
    p->data = x;
    p->left = p->right = NULL;
    p->height = 1;
    return p;
}

int height(node* n) {
    return n == NULL ? 0 : n->height;
}

int getBalanceFactor(node* n) {
    return n == NULL ? 0 : height(n->left) - height(n->right);
}

node* rotateRight(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node* rotateLeft(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node* insert(node* root, int x) {
    if (root == NULL)
        return create(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && x < root->left->data)
        return rotateRight(root);

    if (balance < -1 && x > root->right->data)
        return rotateLeft(root);

    if (balance > 1 && x > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && x < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

node* maxValue(node* tree) {
    node* p = tree;
    while (p && p->right != NULL)
        p = p->right;
    return p;
}

node* minValue(node* tree) {
    node* p = tree;
    while (p && p->left != NULL)
        p = p->left;
    return p;
}

node* remove(node* root, int x) {
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = remove(root->left, x);
    else if (x > root->data)
        root->right = remove(root->right, x);
    else {
        if (root->left == NULL || root->right == NULL) {
            node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            delete temp;
        } else {
            node* temp = minValue(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void traversal(node* root) {
    if (root != NULL) {
        traversal(root->left);
        cout << root->data << " ";
        traversal(root->right);
    }
}
