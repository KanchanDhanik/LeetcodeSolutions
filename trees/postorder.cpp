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
void postorderhelper(struct Node*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    postorderhelper(root->left,ans);
    postorderhelper(root->right,ans);
    ans.push_back(root->data);
}
vector<int>postorder(struct Node*root){
    vector<int>ans;
    postorderhelper(root,ans);
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
vector<int>ans=postorder(root);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
    }
    return 0;
}