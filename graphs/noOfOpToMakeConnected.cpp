#include<bits/stdc++.h>
using namespace std;



int findParent(int x,vector<int>&parent){
    if(x==parent[x])return x;
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


int makeConnections(vector<vector<int>>&network,int n){
    int e=network.size();
    if(e<n-1)return -1;

    vector<int>parent(n);
    vector<int>rank(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int component=n;
    for(auto &vec:network){
        int a=vec[0];
        int b=vec[1];
        int x=findParent(a,parent);
        int y=findParent(b,parent);
        if(x!=y){
            unionByRank(a,b,parent,rank);
            component--;
        }
    }
    return  component-1;
}
int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>>adj(e);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[i]={u,v};
    }

    int check=makeConnections(adj,n);
    if(check!=-1)cout<<" minimum No of operations ; "<<check;
    else cout<<"NOT POSSIBLE";
}