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

vector<int>bottomView(Node*root){
    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        Node*curr=p.first;
        int vertical=p.second;
        mpp[vertical]=curr->data;
        if(curr->left)q.push({curr->left,vertical-1});
        if(curr->right)q.push({curr->right,vertical+1});
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
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<int>ans=bottomView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}