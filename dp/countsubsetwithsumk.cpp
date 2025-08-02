#include<bits/stdc++.h>
using namespace std;
/*
int subsetSum(vector<int>&arr,int i,int target,vector<vector<int>>&dp){
    if(target==0){
        return 1;
    }
    if(i==arr.size()-1){
        return (arr[i]==target)?1:0;
    }
    if(i>=arr.size()){
        return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    //take or nottake;
    int nottake=subsetSum(arr,i+1,target,dp);
    int take=0;
    if(arr[i]<=target){
        take=subsetSum(arr,i+1,target-arr[i],dp);
    }
    return dp[i][target]=take+nottake;

}


*/
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    //vector<vector<int>>dp(n,vector<int>(k+1,0));
    vector<int>prev(k+1,0);

    int cnt=0;
    prev[0]=1;
    if(arr[0]<=k){
        prev[arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        vector<int>curr(k+1,0);
        curr[0]=1;
        for(int j=0;j<=k;j++){
            int nottake=prev[j];
            int take=0;
            if(arr[i]<=j){
                take=prev[j-arr[i]];
            }
            curr[j]=take+nottake;
        }
        prev=curr;
    }
    cout<<prev[k];
}