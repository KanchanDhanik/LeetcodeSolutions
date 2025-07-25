#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1])){
            return arr[mid];
        }
        if(arr[mid]>arr[mid-1]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=binarySearch(arr);
    cout<<"peak found : "<<ans;
}