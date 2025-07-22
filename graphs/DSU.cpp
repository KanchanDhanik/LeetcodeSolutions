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
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<vector<int>>adj(v);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>parent(v);
    vector<int>rank(v);
    for(int i=0;i<v;i++){
        parent[i]=i;
        rank[i]=1;
    }
    bool flag=false;
    //cycle detection 
    for(int u=0;u<v;u++){
        for(int&v:adj[u]){
            if(u<v){
                int x=findParent(u,parent);
                int y=findParent(v,parent);
                if(x==y){
                    flag=true;
                    break;
                }
                unionByRank(u,v,parent,rank);
            }
        }
    }
    if(flag==false)cout<<"No cycle found";
    else cout<<"cycle found";
}