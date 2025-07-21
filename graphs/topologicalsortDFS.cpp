#include<bits/stdc++.h>
using namespace std;

void topologicalSortDfs(int u,vector<bool>&vis,stack<int>&st,unordered_map<int,vector<int>>&adj){
    vis[u]=true;
    for(int&v:adj[u]){
        if(!vis[v]){
            topologicalSortDfs(v,vis,st,adj);
        }
    }
    st.push(u);
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
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            topologicalSortDfs(i,vis,st,adj);
        }
    }
    vector<int>res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    cout<<endl;
    for(int &it:res){
        cout<<it<<" ";
    }
}