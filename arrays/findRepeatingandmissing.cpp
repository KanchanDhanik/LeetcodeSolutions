#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int s=n*(n+1)/2;
    int s2n=n*(n+1)*(2*n+1)/6;

    int s1=0;
    int s2=0;
    for(auto &num:arr){
        s1+=num;
        s2+=num*num;
    }

    int c1=s1-s;
    int c2=s2-s2n;

    int val1=(c1+c2/c1)/2;
    int val2=val1-c1;
    cout<<val1<<" "<<val2;
}