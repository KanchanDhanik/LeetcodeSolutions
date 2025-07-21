#include<bits/stdc++.h>
using namespace std;

bool bfs(int i,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
    queue<pair<int,int>>q;
    q.push({i,-1});
    vis[i]=true;
    while(!q.empty()){
        pair<int,int>&it=q.front();
        q.pop();

        int u=it.first;
        int parent=it.second;
        for(auto &v:adj[u]){
            if(!vis[v]){
                q.push({v,u});
            }else if(v!=parent){
                return true;
            }
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
        if(!vis[i] && bfs(i,adj,vis)){
            cout<<"Cycle found"<<endl;
            break;
        }
    }
    return 0;
}