#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int soe[100001];
    for(int i=0;i<=100000;i++){
        soe[i]=i;
    }

    for(int i=2;i*i<=100000;i++){
        if(soe[i]==i){
            for(int j=i*i;j<=100000;j+=i){
                if(soe[j]==j){
                    soe[j]=i;
                }
            }
        }
    }

    while(n!=1){
        cout<<soe[n]<<" ";
        n=n/soe[n];
    }
}