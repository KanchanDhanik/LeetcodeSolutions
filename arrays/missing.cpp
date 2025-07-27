#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int sum=(n*(n+1))/2;
    int sum2=accumulate(arr.begin(),arr.end(),0);
    cout<<sum-sum2;
}