#include<bits/stdc++.h>
using namespace std;

void topologicalsort(int i,stack<int>&st,vector<pair<int,int>>adj[],vector<int>&vis){
    vis[i]=true;
    for(auto &p:adj[i]){
        int v=p.first;
        if(!vis[v]){
            topologicalsort(v,st,adj,vis);
        }
    }
    st.push(i);
}


int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topologicalsort(i,st,adj,vis);
        }
    }

    vector<int>dist(n,1e9);
    int src;
    cin>>src;
    dist[src]=0;

    while(!st.empty()){
        int u=st.top();
        st.pop();


        for(auto &p:adj[u]){
            int v=p.first;
            int w=p.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==1e9)cout<<"-1";
        else cout<<dist[i]<<" ";
    }
}