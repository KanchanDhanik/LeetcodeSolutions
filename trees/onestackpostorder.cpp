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
    struct Node*curr=root;
    struct Node*temp;
    while(curr!=nullptr || !st1.empty()){
        if(curr!=NULL){
        st1.push(curr);
        curr=curr->left;
        }else{
            temp=st1.top()->right;
            if(temp==nullptr){
                temp=st1.top();
                st1.pop();
            ans.push_back(temp->data);
            while(!st1.empty() && st1.top()->right==temp){
                temp=st1.top();
                st1.pop();
                ans.push_back(temp->data);
            }
        }else{
                curr=temp;
            }
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
vector<int>ans=postorder(root);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
    }
    return 0;
}