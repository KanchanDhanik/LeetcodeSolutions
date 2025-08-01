#include<bits/stdc++.h>
using namespace std;
/*
vector<vector<int>>dp;

int findmin(vector<int>&arr,int idx,int cnt){
    if(idx>=arr.size()-1){
        return cnt;
    }
    if(dp[idx][cnt]!=-1)return dp[idx][cnt];
    int mini=INT_MAX;
    for(int i=1;i<=arr[idx];i++){
        mini=min(mini,findmin(arr,idx+i,cnt+1));
    }
    return dp[idx][cnt]=mini;
}

bool findcanjump(vector<int>&arr,int idx){
    if(idx>=arr.size()-1){
        return true;
    }
    for(int i=1;i<=arr[idx];i++){
        if(findcanjump(arr,idx+i)){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool canjump=findcanjump(arr,0);
    int minsteps=findmin(arr,0,0);
    if(canjump){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    cout<<minsteps<<endl;
}*/
/*Problem Statement:

Given a number of stairs and a frog, the frog wants to
 climb from the 0th stair to the (N-1)th stair. At a time 
 the frog can climb either one or two steps. A height[N] 
 array is also given. Whenever the frog jumps from a stair 
 i to stair j, the energy consumed in the jump is 
 abs(height[i]- height[j]), where abs() means the absolute
  difference. We need to return the minimum energy that
   can be used by the frog to jump from stair 0 to stair N-1.*/


   vector<int>dp;
int findminenergy(vector<int>&arr,int idx){
    if(idx==0)return 0;
    if(dp[idx]!=-1)return dp[idx];
    //now we have two options either to take one step or two step
    int one=INT_MAX,two=INT_MAX;
    one=findminenergy(arr,idx-1)+abs(arr[idx]-arr[idx-1]);
    two=findminenergy(arr,idx-2)+abs(arr[idx]-arr[idx-2]);
    return dp[idx]=min(one,two);
}


   int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp.resize(n+1,0);
    int prev2=0;
    int prev1=abs(arr[1]-arr[0]);
    //int minenergy=findminenergy(arr,n-1);
    for(int i=2;i<n;i++){
        int one=INT_MAX,two=INT_MAX;
    one=prev1+abs(arr[i]-arr[i-1]);
    two=prev2+abs(arr[i]-arr[i-2]);
     int curr=min(one,two);
     prev2=prev1;
     prev1=curr;
    }
    cout<<prev1<<endl;
}