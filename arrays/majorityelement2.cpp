#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt1=0,cnt2=0;
    int mje1,mje2;
    for(int i=0;i<n;i++){
        if(arr[i]==mje1){
            cnt1++;
        }else if(arr[i]==mje2){
            cnt2++;
        }else if(cnt1==0){
            mje1=arr[i];
        }else if(cnt2==0){
            mje2=arr[i];
        }else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==mje1)cnt1++;
        if(arr[i]==mje2)cnt2++;
    }
    if(cnt1>n/3)cout<<mje1<<endl;
    if(cnt2>n/3)cout<<mje2<<endl;
}