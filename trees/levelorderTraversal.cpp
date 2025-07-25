#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node*left;
Node*right;
Node(int val){
    data=val;
    left=NULL;
    right=NULL;
}
};
vector<int>levlorder(struct Node*root){
    queue<struct Node*>q;
    q.push(root);
    vector<int>ans;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
        struct Node*temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
        }
    }
    return ans;
}
int main(){
struct  Node*root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->right->left=new Node(6);
root->right->right=new Node(7);
vector<int>ans=levlorder(root);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
    }
    return 0;
}