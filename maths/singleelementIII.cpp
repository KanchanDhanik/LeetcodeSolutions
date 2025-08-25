#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int xorr=0;
    for(int &num:arr){
        xorr=xorr^num;
    }

    //now we will find the rightmost set bit
    int rightmost=(xorr&(xorr-1))^xorr;
    int b1=0,b2=0;
    for(int &num:arr){
        if(num&rightmost){
            b1^=num;
        }else{
            b2^=num;
        }
    }
    cout<<b1<<" "<<b2;
}
