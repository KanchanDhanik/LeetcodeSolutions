#include<bits/stdc++.h>
using namespace std;

int isPossible(vector<int>&arr,int pages,int student){
    int n=arr.size();
    int currst=1;
    int pageallocated=arr[0];
    for(int i=1;i<n;i++){
        if(pageallocated+arr[i]<=pages){
            pageallocated+=arr[i];
        }else{
            currst++;
            pageallocated=arr[i];
        }
    }
    return currst;
}
int findMaximumMinPages(vector<int>&arr,int m){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=low+(high-low)/2;
        int stu=isPossible(arr,mid,m);
        if(stu>m){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxminpages=findMaximumMinPages(arr,m);
    cout<<maxminpages<<endl;
}