#include<bits/stdc++.h>
using namespace std;

void bfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<int>&res){
    queue<int>q;
    q.push(u);
    vis[u]=true;
    res.push_back(u);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int&v:adj[node]){
            if(!vis[v]){
                q.push(v);
                vis[v]=true;
                res.push_back(v);
            }
        }
    }
}
int main(){
    int V;
    cin>>V;
    int E;
    cin>>E;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>res;
    vector<bool>vis(V,false);
    bfs(0,adj,vis,res);
    cout<<endl;
    for(int i=0;i<V;i++){
        cout<<res[i]<<" ";
    }
}