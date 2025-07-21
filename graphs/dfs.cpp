#include<bits/stdc++.h>
using namespace std;

void dfs(int u,unordered_map<int,vector<int>>&adj,vector<int>&res,vector<bool>&vis){
    if(vis[u]==true)return;
    vis[u]=true;
    res.push_back(u);
    for(int &v:adj[u]){
        if(!vis[v]){
            dfs(v,adj,res,vis);
        }
    }
}
int main(){
    int V;
    cin>>V;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<V;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>res;
    vector<bool>vis(V,false);
    dfs(0,adj,res,vis);
    cout<<endl;
    for(int i=0;i<V;i++){
        cout<<res[i]<<" ";
    }
}