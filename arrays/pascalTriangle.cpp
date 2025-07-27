#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>pascal(n);
    for(int i=0;i<n;i++){
        pascal[i]=vector<int>(i+1,1);
        for(int j=1;j<i;j++){
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<pascal[i][j]<<" ";
        }
        cout<<endl;
    }
}