#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    vector<int>howmany(n-1,0);
    priority_queue<pair<double long,int>>pq;

    for(int i=0;i<n-1;i++){
        int diff=(arr[i+1]-arr[i]);
        pq.push({diff,i});
    }

    for(int gas=1;gas<=k;gas++){
        auto tp=pq.top();
        pq.pop();
        int secIdx=tp.second;
        howmany[secIdx]++;
        long double diff=arr[secIdx+1]-arr[secIdx];
        long double newSec=diff/((long double)howmany[secIdx]+1);
        pq.push({newSec,secIdx});
    }
    cout<<pq.top().first;
}