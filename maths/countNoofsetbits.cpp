#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    /*while(n!=0){
        //turn the rightmostbit to 0 one by one
        n=n&(n-1);
        cnt++;
    }
    cout<<cnt;*/
    //second ,ethod is brute divide by 2 
    while(n>0){
        if(n&1)cnt++;
        n=(n>>1);
    }
    cout<<cnt;
}