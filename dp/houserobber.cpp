#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int prev=arr[0];
    int prev2=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        int skip=prev2;
        int take=prev +arr[i];
        int curr=max(skip,take);
        prev=prev2;
        prev2=curr;
    }
    cout<<prev2;
}

/*
house robber 2


class Solution {
public:
int robhelper(vector<int>&arr,int start,int end){
    if(end-start==1)return arr[start];
    if(end-start==2)return max(arr[start],arr[start+1]);
    int prev=arr[start];
    int prev2=max(arr[start],arr[start+1]);
    for(int i=start+2;i<end;i++){
        int curr=max(prev2,arr[i]+prev);
        prev=prev2;
        prev2=curr;
    }
    return prev2;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int first=robhelper(nums,0,nums.size()-1);
        int last=robhelper(nums,1,nums.size());
        return max(first,last);
    }
};*/