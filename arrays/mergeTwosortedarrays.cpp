#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>arr2(m);
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int left=n-1;
    int right=0;
    while(left>=0 && right<m){
        if(arr[left]>arr2[right]){
            swap(arr[left],arr2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }

}