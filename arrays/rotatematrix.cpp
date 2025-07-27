#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<m;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

    for(auto&v:mat){
        reverse(v.begin(),v.end());
    }
    cout<<endl;
    for(auto&v:mat){
        for(auto&x:v){
            cout<<x<<" ";
        }
            cout<<"\n";
     }

}