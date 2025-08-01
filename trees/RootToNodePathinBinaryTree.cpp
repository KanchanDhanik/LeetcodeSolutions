#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool pathExists(TreeNode*root,int val,vector<int>&ans){

    if(root==NULL){
        return false;
    }

    ans.push_back(root->val);

    if(pathExists(root->left,val,ans) ||pathExists(root->right,val,ans)|| root->val==val){
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int>findPath(TreeNode*root,int val){
    vector<int>path;
    if(root==NULL){
        return path;
    }
    bool flag=pathExists(root,val,path);
    if(!flag){
        cout<<"Nopath exist";
        return path;
    }
    return path;
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

    vector<int>path=findPath(root,-1);
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
}