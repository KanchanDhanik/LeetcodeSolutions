#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&arr,int k,vector<int>dp){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minsteps=INT_MAX;
        for(int j=1;j<=k;j++){
            int jumps=dp[i-j]+abs(arr[i]-arr[i-j]);
            minsteps=min(minsteps,jumps);
        }
        dp[i]=minsteps;
    }
    return dp[n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int>dp(n,-1);
    cout<<solve(n,arr,k,dp);

}