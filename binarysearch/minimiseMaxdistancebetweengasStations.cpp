#include<bits/stdc++.h>
using namespace std;
float findminmaxdist(vector<int>&arr,int k){
int n=arr.size();
float low=0;
float high=0;
for(int i=0;i<n;i++){
    high=max(high,(float)(arr[i+1]-arr[i]));
}
float diff=1e-6;
while(high-low>)
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
    float ans=findminmaxdist(arr,k);
    cout<<ans;
}