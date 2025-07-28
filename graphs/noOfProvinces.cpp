#include<bits/stdc++.h>
using namespace std;

int findParent(int x,vector<int>&parent){
    if(x==parent[x])return x;
    else return parent[x]=findParent(parent[x],parent);
}

void unionByRank(int u,int v,vector<int>&parent,vector<int>&rank){
    int x=findParent(u,parent);
    int y=findParent(v,parent);
    if(x!=y){
        if(rank[x]>rank[y]){
            parent[y]=x;
        }else if(rank[y]>rank[x]){
            parent[x]=y;
        }else{
            parent[y]=x;
            rank[y]++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>isConnected(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>isConnected[i][j];
        }
    }
    vector<int>parent(n);
    vector<int>rank(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int component=n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isConnected[i][j]==1){
              int u=i;
              int v=j;
              int x=findParent(u,parent);
              int y=findParent(v,parent);
              if(x!=y){
                unionByRank(x,y,parent,rank);
                component--;
              }
            }
        }
    }
    cout<<component<<endl;

}