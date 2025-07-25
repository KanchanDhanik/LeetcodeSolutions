#include<bits/stdc++.h>
using namespace std;
int findsqrt(int n){
    int low=0;
    int high=n;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        int val=mid*mid;
        if(val<=n){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int ans=findsqrt(n);
    cout<<ans;
}