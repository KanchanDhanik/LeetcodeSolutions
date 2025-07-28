#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int helper(int index,vector<int>&arr,int k,int currsum){
    if(index==arr.size()){
        if(currsum==k){
            return 1;
        }
        return 0;
    }
  //  if(dp[index][currsum]!=-1)return dp[index][currsum];
    //two choices to take or nottake
    int nottake=helper(index+1,arr,k,currsum);
    int take=helper(index+1,arr,k,currsum+arr[index]);
    return take+nottake;
}

int findsubseq(vector<int>arr,int k){
    int currsum=0;
    return helper(0,arr,k,currsum);
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
  //  dp.resize(n,vector<int>(k+1,-1));
    int cnt=findsubseq(arr,k);
    cout<<cnt;
}