/* Given question that a hiker want to hike but he always want to move downhill and avoid up hill if he faces up hill he 
digs the hill untill it is smaller then the prev so that he can move down wards he can dig 2*d-1 meters in dth day
we have to find maximum number of days requeries to make the terrain downward slopping*/
#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int findDays(vector<int>&arr){
    int n=arr.size();
    int maxdays=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1])continue;
        else{
            int  required=arr[i]-(arr[i-1]-1);
            int days=ceil(sqrt(required));

            arr[i]=arr[i-1]-1;
            maxdays=max(maxdays,days);
        }
    }
    return maxdays;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=findDays(arr);
    cout<<ans<<endl;
}