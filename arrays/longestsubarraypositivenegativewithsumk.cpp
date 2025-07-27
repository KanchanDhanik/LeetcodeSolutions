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
    long long sum=0;
    int maxlen=0;
    unordered_map<long long,int>mpp;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }

        int rem=sum-k;
        if(mpp.find(rem)!=mpp.end()){
            int len=i-mpp[rem];
            maxlen=max(maxlen,len);
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
        }
    }
    cout<<maxlen;
}