#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp=arr[0];
   /* for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    cout<<"one place"<<endl;
    arr[n-1]=temp;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }*/
    cout<<"k places";
    int k;
    cin>>k;
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+(n-k));
    reverse(arr.begin()+(n-k),arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
}}