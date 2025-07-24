#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>&grid,int i,int j,string &temp,vector<string>&paths){
    int n=grid.size();
    if(i>=n ||j>=n){
        return;
    }
    if(i==n-1 && j==n-1){
        paths.push_back(temp);
        return;
    }
    grid[i][j]=0;
    string dir="UDLR";
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    for(int k=0;k<4;k++){
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(nr<n && nc<n &&nr>=0 && nc>=0 && grid[nr][nc]==1){
            temp.push_back(dir[k]);
            helper(grid,nr,nc,temp,paths);
            temp.pop_back();
        }
    }
    grid[i][j]=1;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    vector<string>paths;
    string temp="";
    helper(mat,0,0,temp,paths);
    for(auto &it:paths){
        cout<<it<<"  ";
    }
}