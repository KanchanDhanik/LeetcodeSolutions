#include<bits/stdc++.h>
using namespace std;


int findParent(int x,vector<int>&parent){
    if(parent[x]==x)return x;
    return parent[x]=findParent(parent[x],parent);
}

void unionByRank(int u,int v,vector<int>&parent,vector<int>&rank){
    int x=findParent(u,parent);
    int y=findParent(v,parent);
    if(x==y)return;
    if(rank[x]<rank[y]){
        parent[x]=y;
    }else if(rank[x]>rank[y]){
        parent[y]=x;
    }else{
        parent[x]=y;
        rank[x]++;
    }
}

int main(){
    int n;
    cin>>n; 
    int e;
    cin>>e;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
        edges.push_back({w,{v,u}});
    }
    sort(edges.begin(),edges.end());
    int mstwt=0;
    vector<int>rank(n,1);
    vector<int>parent(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(auto it:edges){
        int w=it.first;
        int u=it.second.first;
        int v=it.second.second;
        int x=findParent(u,parent);
        int y=findParent(v,parent);
        if(x!=y){
            mstwt+=w;
            unionByRank(u,v,parent,rank);
        }
    }
    cout<<mstwt<<endl;
}