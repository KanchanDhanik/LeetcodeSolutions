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
    int first=-1,second=-1;
    for(int i=0;i<n;i++){
        int rem=k-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            first=mpp[rem];
            second=i;
        }
        mpp[arr[i]]=i;
    }
    cout<<first<<" ";
    cout<<second;
}