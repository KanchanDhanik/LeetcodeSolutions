#include<bits/stdc++.h>
using namespace std;

/*int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int furthest=0;
    int l=0,r=0;
    int jumps=0;
    for(int i=0;i<n;i++){
        for(int j=l;j<=r;j++){
            furthest=max(furthest,j+arr[j]);
        }
        l=r+1;
        r=furthest;
        jumps++;
        if(r>=n-1)break;
    }
    cout<<jumps;
}*/

//vector<vector<int>>dp;
/*int helper(vector<int>&arr,int ind,int jumps){
    if(ind>=arr.size()-1){
        return jumps;
    }
    int mini=INT_MAX;
    if(dp[ind][jumps]!=1e9)return dp[ind][jumps];
    for(int i=1;i<=arr[ind];i++){
        mini=min(mini,helper(arr,ind+i,jumps+1));
    }
    return dp[ind][jumps]=mini;
}*/
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //dp.resize(n,vector<int>(n,1e9));
   // int jumps=helper(arr,0,0);
   vector<int>dp(n,1e9);
   int mini=1e9;
   dp[0]=0;
   for(int i=0;i<n;i++){
    for(int j=1;j<=arr[i] && i+j<n;j++){
        dp[i+j]=min(dp[i+j],1+dp[i]);
    }
   }
    cout<<dp[n-1];
}