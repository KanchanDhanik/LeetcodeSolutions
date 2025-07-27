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
    int xorval=0;
    int cnt=0;
    unordered_map<int,int>mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        xorval^=arr[i];
        int x=xorval^k;
        cnt+=mpp[x];
        mpp[xorval]++;
    }
    cout<<cnt;
}