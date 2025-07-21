#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis){
    vis[u]=true;
    for(int i=0;i<adj.size();i++){
        if(adj[u][i]==1 && !vis[i])dfs(i,adj,vis);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<bool>vis(v,false);
        int cnt=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>>provinces(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>provinces[i][j];
        }
    }
    int ans=s.findCircleNum(provinces);
    cout<<ans;
    
}