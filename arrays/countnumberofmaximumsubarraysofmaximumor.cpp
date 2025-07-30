#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int helper(vector<int>&arr,int idx,int curror,int maxor){
    if(idx==arr.size()){
        if(curror==maxor){
            return 1;
        }
        return 0;
    }

    if(curror==maxor){
        return 1<<(arr.size()-idx);
    }
    if(dp[idx][curror]!=-1)return dp[idx][curror];
    int take=helper(arr,idx+1,curror|arr[idx],maxor);
    int nottake=helper(arr,idx+1,curror,maxor);
    return dp[idx][curror]=take+nottake;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxor=0;
    for(int i=0;i<n;i++){
        maxor=maxor|arr[i];
    }
dp.resize(maxor+1,vector<int>(maxor+1,-1));
    int cnt=helper(arr,0,0,maxor);
    cout<<cnt<<endl;
}