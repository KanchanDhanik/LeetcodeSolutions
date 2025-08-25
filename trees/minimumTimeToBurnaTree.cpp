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

Node*assignParent(Node*root,unordered_map<Node*,Node*>&parentmap,int val){
    queue<Node*>q;
    q.push(root);
    Node*startNode;
    while(!q.empty()){
        Node*node=q.front();
        q.pop();
        if(node->data==val)startNode=node;
        if(node->left){
            parentmap[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parentmap[node->right]=node;
            q.push(node->right);
        }
    }
    return startNode;
}
int findMinTimetoBurn(Node*root,int val){
    //step one assign parent pointers
    unordered_map<Node*,Node*>parentmap;
    Node*startnode=assignParent(root,parentmap,val);
    unordered_map<Node*,bool>vis;
    queue<Node*>q;
    q.push(startnode);
    vis[startnode]=true;
    int time=0;
    while(!q.empty()){
        int n=q.size();
        bool flag=false;
        for(int i=0;i<n;i++){
            Node*node=q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                flag=true;
                q.push(node->left);
                vis[node->left]=true;
            }

            if(node->right && !vis[node->right]){
                flag=true;
                q.push(node->right);
                vis[node->right]=true;
            }

            if(parentmap.count(node) && !vis[parentmap[node]]){
                flag=true;
                q.push(parentmap[node]);
                vis[parentmap[node]]=true;
            }
        }

        if(flag){
            time++;
        }
    }
    return time;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->right=new Node(7);
    root->right->left=new Node(5);
    root->right->right=new Node(6);

    int minTimetoBurn=findMinTimetoBurn(root,2);
    cout<<minTimetoBurn<<endl;
}