#include<bits/stdc++.h>
using namespace std;
int canDivide(vector<int>&arr,int sum){
    int n = arr.size();
    int currsum=arr[0];
    int parts=1;
    for(int i=1;i<n;i++){
        if(currsum+arr[i]<=sum){
            currsum+=arr[i];
        }else{
            parts++;
            currsum=arr[i];
        }
    }
    return parts;
}
int findMinLargestSum(vector<int>&arr,int k){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=low+(high-low)/2;
        int subarCnt=canDivide(arr,mid);
        if(subarCnt<=k){
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
    int k;
    cin>>k;
    int minilargestSum=findMinLargestSum(arr,k);
    cout<<minilargestSum<<endl;
}