#include<bits/stdc++.h>
using namespace std;

int spanningTree(int v,vector<vector<int>>adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(v,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;

        if(vis[node]==1)continue;
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            int adjNode=it[0];
            int weight=it[1];
            if(vis[adjNode]==0){
                pq.push({weight,adjNode});
            }
        }
    }
    return sum;
}
int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<vector<int>>edges(e,vector<int>(3));
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>edges[i][j];
        }
    }
	vector<vector<int>> adj[v];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}
    int ans=spanningTree(v,adj);
}