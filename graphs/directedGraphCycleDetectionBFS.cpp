#include<bits/stdc++.h>
using namespace std;

bool bfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<bool>&inRec){
    
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
    }
    vector<bool>vis(V,false);
    vector<bool>inRec(V,false);
    bool cycle=false;
    for(int i=0;i<V;i++){
        if(!vis[i] && bfs(i,adj,vis,inRec)){
            cycle=true;
            break;
        }
    }
    cout<<(cycle?"cycle found":"No cycle Found")<<endl;
    return 0;
}