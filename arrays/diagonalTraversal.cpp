/*diagonal zigzag traversal of a 2D matrix*/

#include<bits/stdc++.h>
using namespace std;
vector<int>diagonalTraverse(vector<vector<int>>&mat,int n,int m){
    map<int,vector<int>>mpp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mpp[i+j].push_back(mat[i][j]);
        }
    }
    vector<int>ans;
    bool flag=true;
    for(auto &v:mpp){
        if(flag){
            reverse(v.second.begin(),v.second.end());
        }
        for(auto &num:v.second){
            ans.push_back(num);
        }
        flag=!flag;
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    cout<<endl<<endl;
    vector<int>ans=diagonalTraverse(mat,n,m);
    for(auto &num:ans){
        cout<<num<<" ";
    }
}