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

void change(Node*root){
    if(root==NULL){
        return;
    }
    int child=0;
    if(root->left)child+=root->left->val;
    if(root->right)child+=root->right->val;

    if(child>=root->val){
        root->val=child;
    }else{
        if(root->left)root->left->val=root->val;
        if(root->right)root->right->val=root->val;
    }

    change(root->left);
    change(root->right);

    int total=0;
    if(root->left)total+=root->left->val;
    if(root->right)total+=root->right->val;
    if(root->left || root->right)root->val=total;
}

void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
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
    inorder(root);

    change(root);
    cout<<endl;
    inorder(root);
}
