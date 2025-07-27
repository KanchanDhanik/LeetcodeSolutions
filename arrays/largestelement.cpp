#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxi=INT_MIN;
    int secondmaxi=INT_MIN;
    for(int i=0;i<n;i++){
       if(arr[i]>=maxi){
        secondmaxi=maxi;
        maxi=arr[i];
       }else if(arr[i]>secondmaxi){
        secondmaxi=arr[i];
       }
    }
    cout<<maxi;
    cout<<secondmaxi;
}