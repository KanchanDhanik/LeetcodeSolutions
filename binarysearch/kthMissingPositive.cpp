#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    int ans=k+low;
    cout<<ans;
}