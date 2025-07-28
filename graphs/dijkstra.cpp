#include<bits/stdc++.h>
using namespace std;


vector<int>dijkstra(int v,vector<vector<int>>adj[],int s){
    vector<int>dist(v,1e9);
    dist[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        int node=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        for(auto &p:adj[node]){
            int v=p[0];
            int wt=p[1];
            if(w+wt<dist[v]){
                dist[v]=w+wt;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;

}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<vector<int>>adj[v];
    for(int i=0;i<e;i++){
        int u,v1,w;
        cin>>u>>v1>>w;
        adj[u].push_back({v1,w});
        adj[v1].push_back({u,w});
    }
    int src;
    cin>>src;
    vector<int>dist=dijkstra(v,adj,src);
    for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
    }
}