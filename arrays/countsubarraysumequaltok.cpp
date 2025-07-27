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
    unordered_map<int,int>presum;
    int sum=0;
    int res=0;
    presum[0]=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int rem=sum-k;
        if(presum.find(rem)!=presum.end()){
            res+=presum[rem];
        }
        presum[sum]++;
    }
    cout<<res;
}