#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    unordered_map<int,vector<int>>adj;
    for(auto&e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int>dist(n,1e9);
    int src;
    cin>>src;
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto&v:adj[u]){
            if(1+dist[u]<dist[v]){
                dist[v]=1+dist[u];
                q.push(v);
            }
        }
    }
    for(int&d:dist){
        if(d==1e9)cout<<"-1";
        else cout<<d<<" ";
    }
}