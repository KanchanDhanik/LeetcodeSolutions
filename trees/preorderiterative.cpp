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
vector<int>preorder(struct Node*root){
    vector<int>ans;
    stack<struct Node*>st;
    st.push(root);
    while(!st.empty()){
        struct Node*temp=st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right)st.push(temp->right);
        if(temp->left)st.push(temp->left);
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
vector<int>ans=preorder(root);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
    }
    return 0;
}