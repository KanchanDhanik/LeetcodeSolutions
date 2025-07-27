#include<bits/stdc++.h>
using namespace std;
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
    int i=0,j=0;
    vector<int>ans;
    while(i<n && j<m){
        if(arr[i]<=arr2[j]){
            if(ans.size()==0 || ans.back()!=arr[i])
            ans.push_back(arr[i]);
            i++;
        }else{
            if(ans.size()==0 || ans.back()!=arr2[j])
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        if(ans.size()==0 || ans.back()!=arr[i])
        ans.push_back(arr[i]);
        i++;
    }
    while(j<m){
        if(ans.size()==0 || ans.back()!=arr2[j])
        ans.push_back(arr2[j]);
        j++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}