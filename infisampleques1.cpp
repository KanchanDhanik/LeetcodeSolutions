/*Given an Energy E of a person the person want to do excersise and he have option to do excersize in n machine with energy required
 arr[i] we have to return if the person is able to get tired or not 
 tired= when his enegry is less than or equal to zero after working on the machine return count of the exercise he has done 
 and even after working out his enegy is >zero then return -1
 given condition a person can use machine atmost 2 times only*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findNoofExcer(vector<int>&arr,int e,int n){
    int cnt=0;
    sort(arr.rbegin(),arr.rend());
    for(int i=0;i<n;i++){
        if(e<=0)break;
            e-=arr[i];
            cnt++;
        if(e<=0)break;
            e-=arr[i];
            cnt++;
    }
    return e>0?-1:cnt;
}
using namespace std;
 int main(){
int e,n;
cin>>e>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int count=findNoofExcer(arr,e,n);
cout<<count<<endl;
 }