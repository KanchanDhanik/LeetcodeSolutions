#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

vector<int>leftView(Node*root){
    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node*curr=it.first;
        int level=it.second;
        if(mpp.find(level)==mpp.end()){
            mpp[level]=curr->data;
        }
        if(curr->left!=NULL){
            q.push({curr->left,level+1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,level+1});
    }

    }
    vector<int>ans;
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(11);
    root->right->left = new Node(9);

    vector<int>ans=leftView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}