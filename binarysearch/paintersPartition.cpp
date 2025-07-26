#include<bits/stdc++.h>
using namespace std;
int cntPainters(vector<int>&arr,int k){
    int n = arr.size();
    int curr=1;
    int area=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]+area<=k){
            area+=arr[i];
        }else{
            curr++;
            area=arr[i];
        }
    }
    return curr;
}
int findminpartition(vector<int>arr,int k){
    int n=arr.size();
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int paintercnt=cntPainters(arr,mid);
        if(paintercnt>k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans=findminpartition(arr,k);
    cout<<ans;
}