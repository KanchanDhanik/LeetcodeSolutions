#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

bool isLeaf(Node*node){
    if(node->left==NULL && node->right==NULL){
        return true;
    }
    return false;
}


void addLeftBoundary(Node*root,vector<int>&res){
    Node*curr=root->left;
    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->val);
        }
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}


void addLeaves(Node*root,vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left)addLeaves(root->left,res);
    if(root->right)addLeaves(root->right,res);
}

void addRightBoundary(Node*root,vector<int>&res){
    vector<int>temp;
    Node*curr=root->right;
    while(curr){
    if(!isLeaf(curr)){
        temp.push_back(curr->val);
    }
    if(curr->left){
        curr=curr->left;
    }else{
        curr=curr->right;
    }
}
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
vector<int>boundaryTraversal(Node*root){
    if(root==NULL){
        return {};
    }
    vector<int>ans;
    if(!isLeaf(root)){
        ans.push_back(root->val);
    }

    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
    
}
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    vector<int>ans=boundaryTraversal(root);
    for(auto i:ans){
        cout<<i<<" ";
    }

}