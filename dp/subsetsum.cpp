#include<bits/stdc++.h>
using namespace std;
/*vector<vector<int>>dp;
bool subsetSum(vector<int>&arr,int i,int target){
    if(target==0){
        return true;
    }
    if(i==0){
        return arr[i]==target;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    //nottake
    bool nottake=subsetSum(arr,i-1,target);
    //take
    bool take=false;
    if(arr[i]<=target){
        take=subsetSum(arr,i-1,target-arr[i]);
    }
    return dp[i][target]=take||nottake;
}*/
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=k){
        dp[0][arr[0]]=true;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target){
                take=dp[ind-1][target-arr[ind]];
            }
            dp[ind][target]=nottake||take;
        }
    }
    if(dp[n-1][k]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}