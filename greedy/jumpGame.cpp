#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxindex=0;
    for(int i=0;i<n;i++){
        if(i>maxindex){
            cout<<"not possible";
            break;
        }
        maxindex=max(maxindex,i+arr[i]);
    }
    if(maxindex>=n){
        cout<<"possible";
    }
}