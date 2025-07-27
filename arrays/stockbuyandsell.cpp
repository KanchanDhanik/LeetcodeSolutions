#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int minsofar=arr[0];
    int profit=0;
    int maxprofit=0;
    for(int i=1;i<n;i++){
        minsofar=min(minsofar,arr[i]);
        profit=arr[i]-minsofar;
        maxprofit=max(maxprofit,profit);
    }
    cout<<maxprofit;
}