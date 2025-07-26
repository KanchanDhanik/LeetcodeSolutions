#include<bits/stdc++.h>
using namespace std;


bool canShip(int capacity,vector<int>&weights,int d){
    int n=weights.size();
    int day=1;
    int currCap=0;
    for(int i=0;i<n;i++){
        if(capacity>=currCap+weights[i]){
            currCap+=weights[i];
        }else{
            day++;
            currCap=weights[i];
        }
    }
    return day<=d;
}
int findminweight(vector<int>&weights,int d){
    int low=*min_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canShip(mid,weights,d)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    vector<int>weights(n);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    int d;
    cin>>d;
    int ans=findminweight(weights,d);
    cout<<ans;
}