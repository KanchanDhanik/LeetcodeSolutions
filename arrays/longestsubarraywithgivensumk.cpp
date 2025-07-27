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
    int len=0;
    /*int i=0;//for start point
    int sum=0;
    for(int j=0;j<n;j++){
        sum+=arr[j];
        while(sum>k){
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            len=max(len,j-i+1);
        }
    }*/
   long long presum=0;
   unordered_map<long long,int>mpp;
   for(int i=0;i<n;i++){
    presum+=arr[i];

    if(presum==k){
        len=max(len,i+1);
    }
    int rem=presum-k;
    if(mpp.find(rem)!=mpp.end()){
        int templen=i-mpp[rem];
        len=max(len,templen);
    }
    if(mpp.find(presum)==mpp.end()){
        mpp[presum]=i;
    }
   }
    cout<<len;
}