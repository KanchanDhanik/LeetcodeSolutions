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

bool isSymmetric(Node*root1,Node*root2){
    if(root1==NULL || root2==NULL){
        return root1==root2;
    }


    return (root1->val==root2->val) && isSymmetric(root1->left,root2->right)
    && isSymmetric(root2->left,root1->right);
}


int  main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(2);
    root->right->left = new Node(4);

    bool flag=isSymmetric(root->left,root->right);
    if(flag){
        cout<<"Symmetric"<<endl;
    }else{
        cout<<"Not Symmetric"<<endl;
    }
}