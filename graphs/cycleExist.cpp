#include<bits/stdc++.h>
using namespace std;


bool dfs(int u,int parent,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
    vis[u]=true;


    for(int &v:adj[u]){
        if(v==parent)continue;
        if(vis[v])return true;

        if(dfs(v,u,adj,vis)){
            return true;
        }
    }
    return false;
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
        adj[v].push_back(u);
    }
    vector<bool>vis(V,false);

    for(int i=0;i<V;i++){
        if(!vis[i] && dfs(i,-1,adj,vis)){
            cout<<"Cycle found"<<endl;
            break;
        }
    }
    return 0;
}