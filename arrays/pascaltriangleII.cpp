#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
   vector<int>prev;
    for(int i=0;i<=n;i++){
        vector<int>curr(i+1,1);
        for(int j=1;j<i;j++){
            curr[j]=prev[j-1]+prev[j];
        }
        prev=curr;
    }
    for(auto&num:prev){
        cout<<num<<" ";
    }
}