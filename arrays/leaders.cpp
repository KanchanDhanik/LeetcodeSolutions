#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>leaders;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
        leaders.push_back(arr[i]);
        maxi=max(maxi,arr[i]);
        }
    }
    reverse(leaders.begin(),leaders.end());
    for(int i=0;i<leaders.size();i++){
        cout<<leaders[i]<<" ";
    }
}