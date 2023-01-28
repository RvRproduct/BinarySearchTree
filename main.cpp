#include <iostream>

using namespace std;

struct BinarySearchTree {
    BinarySearchTree* left = NULL;
    BinarySearchTree* right = NULL;
    int value;
    
};

BinarySearchTree* GetNewNode(int val);
BinarySearchTree* insert(BinarySearchTree* root, int val);
bool lookup(BinarySearchTree* root, int val);
void displayPreOrder(BinarySearchTree* root);

BinarySearchTree* GetNewNode(int val) {
    BinarySearchTree* newNode = new BinarySearchTree();
    newNode->value = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BinarySearchTree* insert(BinarySearchTree* root, int val) {
    if(root == NULL) {
        root = GetNewNode(val);
    }
    else if(val <= root->value) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool lookup(BinarySearchTree* root, int val) {
    if (root == NULL) return false;
    if (root->value == val) return true;
    else if(val <= root->value) return lookup(root->left, val);
    else return lookup(root->right, val);
}

void displayPreOrder(BinarySearchTree* root) {
    if (root == NULL)
        return;
    cout << "<" << root->value << ">" << " " << endl;
    
    displayPreOrder(root->left);
    
    displayPreOrder(root->right);
}

int main(){
    BinarySearchTree* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 25);
    cout << lookup(root, 10) << " Found?" << endl;
    cout << lookup(root, 30) << " Found?" << endl;
    
    displayPreOrder(root);

    cout << endl;
    return 0;
}