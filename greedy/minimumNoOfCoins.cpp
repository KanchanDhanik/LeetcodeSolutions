#include<bits/stdc++.h>
using namespace std;
int main(){
    int v;
    cin>>v;
    vector<int>coins={1,2,5,10,20,50,100,500,1000};
    int n=coins.size();
    int cnt=0;
    int i=n-1;
    while(i>=0){
        if(v>=coins[i]){
            v-=coins[i];
            cnt++;
            if(v==0){
                break;
            }
        }else{
            i--;
        }
    }
    cout<<cnt;
}