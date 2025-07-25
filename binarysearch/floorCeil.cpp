#include<bits/stdc++.h>
using namespace std;
int findFloor(vector<int>&arr,int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<=k){
            ans=arr[mid];
            low=mid+1;
        }else{
            high=mid-1;
        }
        
    }
    return ans;
}

int findCeil(vector<int>&arr,int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=k){
            ans=arr[mid];
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
    int flr=findFloor(arr,k);
    int ceill=findCeil(arr,k);
    cout<<"floor of "<<k<<" is "<<flr<<endl;
    cout<<"ceil of "<<k<<" is "<<ceill<<endl;
}