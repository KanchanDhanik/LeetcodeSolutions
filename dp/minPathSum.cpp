#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
int helper(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i<0 ||j<0){
        return 1e9;
    }
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int left=grid[i][j]+helper(i-1,j,grid,dp);
    int up=grid[i][j]+helper(i,j-1,grid,dp);
    return dp[i][j]=min(left,up);
}
    int minPathSum(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
      // vector<vector<int>>dp(n,vector<int>(m,1e9));
      // return helper(n-1,m-1,grid,dp);
      vector<int>prev(m,1e9);
      prev[0]=grid[0][0];
      for(int i=0;i<n;i++){
        vector<int>curr(m,1e9);
        for(int j=0;j<m;j++){
            if(i==0 &&j==0){
                curr[j]=grid[i][j];
                continue;
            }
            int left=(i>0)?grid[i][j]+prev[j]:1e9;
            int up=(j>0)?grid[i][j]+curr[j-1]:1e9;
            curr[j]=min(left,up);
        }
        prev=curr;
      } 
      return prev[m-1];
    }
};