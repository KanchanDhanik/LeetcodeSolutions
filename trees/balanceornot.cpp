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

int maxDepth(Node*root){
    if(root==NULL){
        return 0;
    }
    int lh=maxDepth(root->left);
    if(lh==-1)return-1;
    int rh=maxDepth(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
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

    int depth = maxDepth(root);
    if(depth != -1) {
    cout << "Maximum depth of the binary tree: " << depth << endl;
    }else{
        cout<<"tre is not balanced"<<endl;
    }
    return 0;
}
