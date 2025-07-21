#include<bits/stdc++.h>
using namespace std;


int main(){
    int V;
    cin>>V;
    int E;
    cin>>E;
    unordered_map<int,vector<int>>adj;
    vector<int>inDegree(V,0);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        inDegree[v]++;
        adj[u].push_back(v);
    }
    queue<int>q;
    cout<<endl;
    vector<int>res;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        res.push_back(u);
        for(int&v:adj[u]){
            inDegree[v]--;

            if(inDegree[v]==0){
                q.push(v);
            }
        }
    }
    for(int &it:res){
        cout<<it<<" ";
    }
    return 0;
}