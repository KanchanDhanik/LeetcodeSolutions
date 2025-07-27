#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    int maxcnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt++;
            maxcnt=max(cnt,maxcnt);
        }else{
            cnt=0;
        }
    }
    cout<<maxcnt;
}