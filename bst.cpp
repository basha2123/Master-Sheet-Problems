#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    
    Node (int val){
        data  = val;
        left = right = NULL;
    }
};

Node* insert(Node *root, int val){
    if(root == NULL) return new Node(val);
    if(val < root->data){
        root -> left = insert(root -> left, val);
    }
    else root -> right = insert(root->right,val);
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMin(root->right); 
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root -> left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    
    root = insert(root, 5);
    insert(root, 10);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    
    inorder(root);
    cout << endl;
    
    root = deleteNode(root, 7);
    inorder(root);
    
    return 0;
    
}
