#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        left=right=NULL;
    }
};

vector<vector<int>>verticalOrderTraversal(Node*root){
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<Node*,pair<int,int>>>q;
    q.push({root,{0,0}});

    while(!q.empty()){
        auto p=q.front();
        q.pop();
        Node*temp=p.first;
        int vertical=p.second.first;
        int level=p.second.second;
        nodes[vertical][level].insert(temp->val);

        if(temp->left){
            q.push({temp->left,{vertical-1,level+1}});
        }
        if(temp->right){
            q.push({temp->right,{vertical+1,level+1}});
        }
    }

    vector<vector<int>>ans;
    for(auto vertical:nodes){
        vector<int>vot;
        for(auto val:vertical.second){
            vot.insert(vot.end(),val.second.begin(),val.second.end());
        }
        ans.push_back(vot);
    }
    return ans;
}
int main(){
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
    vector<vector<int>>vot=verticalOrderTraversal(root);
    for(int i=0;i<vot.size();i++){
        for(int j=0;j<vot[i].size();j++){
            cout<<vot[i][j]<<" ";
        }
    }
}