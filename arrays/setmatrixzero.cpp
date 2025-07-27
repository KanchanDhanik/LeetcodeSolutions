#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    int col0=1;

    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]==0){
                mat[i][0]=0;
                if(j!=0){
                    mat[0][j]=0;
                }else{
                    col0=0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]!=0){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]=0;
                }
            }
        }
    }
    //for first row
    if(mat[0][0]==0){
        for(int j=0;j<m;j++){
            mat[0][j]=0;
        }
    }
    //if col0=0 then change whole coln
    if(col0==0){
        for(int i=0;i<n;i++){
            mat[i][0]=0;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}