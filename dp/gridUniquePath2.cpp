#include<bits/stdc++.h>
using namespace std;



int cntWays(vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<int>prev(m,0);
    prev[0]=1;
    if(grid[0][0]==1)return 0;

    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                curr[j]=0;
                continue;
            }
            if(i==0 && j==0){
                curr[j]=1;
                continue;
            }

            if(i>0)curr[j]+=prev[j];
            if(j>0)curr[j]+=curr[j-1];
        }
        prev=curr;
    }
    return prev[m-1];
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int cnt=cntWays(grid);
    cout<<cnt;
}