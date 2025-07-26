#include<bits/stdc++.h>
using namespace std;

int timeToEat(vector<int>&arr,int banana){
    int n=arr.size();
    int hr=0;
    for(int i=0;i<n;i++){
        hr+=ceil((double)arr[i]/banana);
    }
    return hr;
}
int findminhrs(vector<int>&arr,int hrs){
    int n=arr.size();
    
    int low=1;
    int high=*max_element(arr.begin(),arr.end());
    int minhrs=0;
    while(low<=high){
        int mid=low+(high-low)/2;
         minhrs=timeToEat(arr,mid);
        if(minhrs<=hrs){
            high=mid-1;
        }else{
            low=mid+1;
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
    int hrs;
    cin>>hrs;
    int ans=findminhrs(arr,hrs);
    cout<<"koko can eat "<<ans<<" bananas per hour whithin h hours";
}