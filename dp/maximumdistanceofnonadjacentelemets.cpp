#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int helper(vector<int>&arr,int idx){
    if(idx==arr.size()-1){
        return arr[idx];
    }
    if(idx>=arr.size()){
        return 0;
    }
    if(dp[idx]!=-1)return dp[idx];
    //now we have two choice either skip it or take it
    int skip=helper(arr,idx+1);
    //take
    int take=arr[idx]+helper(arr,idx+2);
    return dp[idx]=max(take,skip);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp.resize(n+1,0);
    //int maxsum=helper(arr,0);
   dp[0]=arr[0];
   dp[1]=max(arr[0],arr[1]);
   for(int i=2;i<n;i++){
    int skip=dp[i-1];
    int take=arr[i]+dp[i-2];
    dp[i]=max(skip,take);
   }
   cout<<dp[n-1];
}