#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr,int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        //first identify the sorted part
        if(arr[mid]==k)return mid;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && arr[mid]>=k){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(arr[mid]<=k && k<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
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
    cout<<"enter the element to be searched : ";
    int k;
    cin>>k;
    int ans=binarySearch(arr,k);
    if(ans!=-1){
        cout<<"element found at index : "<<ans;
    }else{
        cout<<"not present in an array";
    }
}