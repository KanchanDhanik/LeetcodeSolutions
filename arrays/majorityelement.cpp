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
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }else if(el==arr[i])cnt++;
        else cnt--;
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el){
            cnt1++;
        }
    }
    if(cnt1>(n/2))cout<<el;
    else cout<<-1;
}