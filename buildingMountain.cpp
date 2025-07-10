#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>mpp;
    if(n&1){
        int mid=n/2;
        for(int i=0;i<mid;i++){
            if(mpp.find(arr[i]-i)==mpp.end()){
                mpp[arr[i]-i]=0;
            }
            mpp[arr[i]-i]++;
        }
        for(int i=mid;i<n;i++){
            if(mpp.find(arr[i]+i-n+1)==mpp.end()){
                mpp[arr[i]+i-n+1]=0;
            }
            mpp[arr[i]+i-n+1]++;
        }
    }else{
        int mid1=n/2-1,mid2=n/2;
        for(int i=0;i<=mid1;i++){
            if(mpp.find(arr[i]-i)==mpp.end()){
                mpp[arr[i]-i]=0;
                }
                mpp[arr[i]-i]++;
                }
        for(int i=mid2;i<n;i++){
            if(mpp.find(arr[i]+i-n+1)==mpp.end()){
                mpp[arr[i]+i-n+1]=0;
                }
                mpp[arr[i]+i-n+1]++;
        }
    }
        int maxfreq=0;
        for(auto it:mpp){
            if(it.second>maxfreq){
                maxfreq=it.second;
                }
        }
        cout<<n-maxfreq<<endl;
}