#include<bits/stdc++.h>
using namespace std;
double findMedian(vector<int>&arr1,vector<int>&arr2,int k){
    int n1=arr1.size();
    int n2=arr2.size();
    if(n1>n2)return findMedian(arr2,arr1,k);
    int n=n1+n2;
    int left=k;

    int low=0;
    int high=n1;
    while(low<=high){
        int mid1=low+(high-low)/2;
        int mid2=left-mid1;

        int l1=(mid1-1>=0)?arr1[mid1-1]:INT_MIN;
        int r1=(mid1<n1)?arr1[mid1]:INT_MAX;
        int l2=(mid2-1>=0)?arr2[mid2-1]:INT_MIN;
        int r2=(mid2<n2)?arr2[mid2]:INT_MAX;

        if(l1<=r2 && l2<=r1){
            if(n%2==1){
                return max(l1,l2);
            }else return (max(l1, l2) + min(r1, r2)) / 2.0;


        }else if(l1>r2){
            high=mid1-1;
        }else{
            low=mid1+1;
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    vector<int>arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int k;
    cin>>k;
    double median=findMedian(arr,arr2,k);
    cout<<median;
}