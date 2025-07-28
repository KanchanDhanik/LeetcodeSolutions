#include<bits/stdc++.h>
using namespace std;



int findShortestPath(vector<vector<int>>&grid,pair<int,int>src,pair<int,int>des){
    if(src.first==des.first && src.second==des.second){
        return 0;
    }
    queue<pair<int,pair<int,int>>>q;
    q.push({0,src});
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[src.first][src.second]=0;

    int dr[]={0,0,-1,1};
    int dc[]={1,-1,0,0};
    while(!q.empty()){
        int u=q.front().second.first;
        int v=q.front().second.second;
        int d=q.front().first;
        q.pop();
        for(int k=0;k<4;k++){
            int nr=u+dr[k];
            int nc=v+dc[k];
            if(nr<n && nc<m && nr>=0 && nc>=0 && grid[nr][nc]==1 && 1+d<dist[nr][nc]){
                dist[nr][nc]=1+d;


                if(nr==des.first && nc==des.second)return d+1;
                q.push({dist[nr][nc],{nr,nc}});

            }
        }
    }
    return -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    pair<int,int>src;
    pair<int,int>des;
    cin>>src.first>>src.second;
    cin>>des.first>>des.second;

    int dist=findShortestPath(grid,src,des);
    cout<<dist;
}