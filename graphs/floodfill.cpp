#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int newColor,sr,sc;
    cin>>sr>>sc>>newColor;
    int originalclr=grid[sr][sc];
    grid[sr][sc]=newColor;
    queue<pair<int,int>>q;
    q.push({sr,sc});
    int dr[]={0,0,-1,1};
    int dc[]={-1,1,0,0};
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int x=it.first;
        int y=it.second;
        for(int k=0;k<4;k++){
            int nr=x+dr[k];
            int nc=y+dc[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]!=0 && grid[nr][nc]==originalclr){
                grid[nr][nc]=newColor;
                q.push({nr,nc});
            }
        }
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
}