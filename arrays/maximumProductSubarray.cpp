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
    int prefix=1;
    int suffix=1;
    for(int i=0;i<n;i++){
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix*=arr[i];
        suffix*=arr[n-i-1];
        maxi=max(maxi,max(prefix,suffix));
    }
    cout<<maxi<<endl;
}