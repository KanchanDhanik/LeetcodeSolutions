/*Given an integer array nums and an integer k, return true 
if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer
 n such that x = n * k. 0 is always a multiple of k.*/


#include<bits/stdc++.h>
using namespace std;

bool isGoodSubarray(vector<int>&nums,int k){
    int n=nums.size();
    unordered_map<int,int>mpp;
    int sum=0;
    mpp[0]=-1;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        int rem=sum%k;
        if(mpp.count(rem)){
            int len=i-mpp[rem];
            if(len>=2){
                return true;
            }
        }else{
            mpp[rem]=i;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    if(isGoodSubarray(nums,k)){
        cout<<"Found a good subarray";
    }else{
        cout<<"doesn't contain a good subarray";
    }
}