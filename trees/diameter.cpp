#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

int maxDepth(Node*root,int &diameter){
    if(root==NULL){
        return 0;
    }
    int lh=maxDepth(root->left,diameter);
    int rh=maxDepth(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return  1+max(lh,rh);
}
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    int diameter=0;
    int depth = maxDepth(root,diameter);

    cout << "Maximum depth of the binary tree: " << depth << endl;
    cout << "Diameter of the binary tree: " << diameter << endl;
    return 0;
}
