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

vector<int>topView(Node*root){
    map<int,int>mpp;//to store vertical line vise element;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int line=it.second;
        Node*temp=it.first;
        if(mpp.find(line)==mpp.end()){
            mpp[line]=temp->data;
        }

        if(temp->left)q.push({temp->left,line-1});
        if(temp->right)q.push({temp->right,line+1});
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

    vector<int>ans=topView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}