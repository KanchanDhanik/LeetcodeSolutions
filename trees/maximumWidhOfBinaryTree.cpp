#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node*left;
Node*right;
Node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
}
};


int width(Node*root){
    if(root==NULL){
        return 0;
    }
    queue<pair<Node*,int>>q;
    int ans=0;
    q.push({root,0});
    while(!q.empty()){
        int n=q.size();
        int mini=q.front().second;
        int first,last;
        for(int i=0;i<n;i++){
            auto it=q.front();
            q.pop();
            Node*node=it.first;
            int curr=it.second-mini;
            if(i==0){
                first=curr;
            }
            if(i==n-1){
                last=curr;
            }
            if(node->left)q.push({node->left,2*curr+1});
            if(node->right)q.push({node->right,2*curr+2});
            
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    int ans=width(root);
    cout<<ans;
}