#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* findlca(TreeNode*root,int a,int b){

    if(root==NULL ||root->val==a ||root->val==b){
        return root;
    }

    TreeNode*left=findlca(root->left,a,b);
    TreeNode*right=findlca(root->right,a,b);

    if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }else{
        return root;
    }
}


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* lca=findlca(root,6,4);
    cout<<lca->val<<endl;
}