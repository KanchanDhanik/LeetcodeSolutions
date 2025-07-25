#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;
        //first identify the sorted part
        if(arr[low]<=arr[high]){
            ans=min(arr[low],ans);
            break;
        }
        if(arr[low]<=arr[mid]){
            ans=min(arr[low],ans);
            low=mid+1;
        }else{
            ans=min(arr[mid],ans);
            high=mid-1;
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
    int ans=binarySearch(arr);
    cout<<"minimum element found : "<<ans;
}