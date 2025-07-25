#include<bits/stdc++.h>
using namespace std;

int bfirst(vector<int>&arr,int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            ans=mid;
            high=mid-1;
        }else if(arr[mid]<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int blast(vector<int>&arr,int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            ans=mid;
            low=mid+1;
        }else if(arr[mid]>k){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the element to be searched : ";
    int k;
    cin>>k;
    int first=bfirst(arr,k);
    int last=blast(arr,k);
    int ans=last-first+1;
    cout<<"No.of occrances of k :"<<ans;
}