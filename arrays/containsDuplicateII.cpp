/*Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    unordered_map<int,int>mpp;
    bool flag=false;
    for(int i=0;i<n;i++){
        int val=arr[i];
        if(mpp.count(val) && abs(i-mpp[val])<=k){
            flag=true;
            break;
        }
        mpp[val]=i;
    }
if(flag)cout<<"duplicate found";
else cout<<"no duplicate found";
}