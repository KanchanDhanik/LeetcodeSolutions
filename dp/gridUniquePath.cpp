/*
class Solution {
public:


int helper(int m,int n,vector<vector<int>>&dp){
    if(m==0 && n==0){
        return 1;
    }
    if(m<0 || n<0){
        return 0;
    }
    if(dp[m][n]!=-1)return dp[m][n];
    //two possible ways either go up or left 
    //for moving left
    int left=helper(m-1,n,dp);
    //for moving up
    int up=helper(m,n-1,dp);
    return dp[m][n]=left+up;
}

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,1));

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int left=dp[i-1][j];
                int right=dp[i][j-1];
                dp[i][j]=left+right;
            }
        }
        return dp[m-1][n-1];
    }
};*/


#include<bits/stdc++.h>
using namespace std;



int countWays(int m,int n){
    vector<int>prev(n,0);
    for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0||j==0){
                temp[j]=1;
                continue;
            }
            int up=0;
            int left=0;
            if(i>0){
                up=prev[j];
            }
            if(j>0){
                left=temp[j-1];
            }
            temp[j]=up+left;
        }
        prev=temp;
    }
    return prev[n-1];
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<countWays(m,n);
}