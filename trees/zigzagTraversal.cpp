#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(7);
    root->left->right->right=new Node(8);


    queue<Node*>q;
    q.push(root);
    bool flag=true;
    vector<vector<int>>ans;
    while(!q.empty()){
        int n=q.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            Node*node=q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        if(flag){
            ans.push_back(temp);
        }else{
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
    }
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
    }
}