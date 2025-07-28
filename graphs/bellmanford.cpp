#include<bits/stdc++.h>
using namespace std;

vector<int>bellman(int n,vector<vector<int>>&edges,int src){
    vector<int>dist(n,1e8);
    dist[src]=0;

    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }

    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        if(dist[u]!=1e8 && dist[u]+w<dist[v]){
            return {-1};
        }
    }
    return dist;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;
    cin>>src;
    vector<int>dist=bellman(n,edges,src);
    cout<<endl;
    for(auto it:dist){
        cout<<it<<" ";
    }
}