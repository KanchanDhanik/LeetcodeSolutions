#include<bits/stdc++.h>
using namespace std;
int findSum(vector<int>&arr,int div){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=ceil((double)arr[i]/div);
    }
    return sum;
}
int findSmallestdivisor(vector<int>&arr,int limit){
   int low=1;
   int high=*max_element(arr.begin(),arr.end());
   while(low<=high){
    int mid=low+(high-low)/2;
    int sum=findSum(arr,mid);
    if(sum<=limit){
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
    int limit;
    cin>>limit;

    int minum=findSmallestdivisor(arr,limit);
    cout<<minum;
}