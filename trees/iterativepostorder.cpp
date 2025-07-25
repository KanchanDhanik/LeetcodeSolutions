#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int>postorder(struct Node*root){
    vector<int>ans;
    stack<struct Node*>st1;
    stack<struct Node*>st2;
    st1.push(root);
    while(!st1.empty()){
        struct Node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left)st1.push(temp->left);
        if(temp->right)st1.push(temp->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
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
vector<int>ans=postorder(root);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
    }
    return 0;
}