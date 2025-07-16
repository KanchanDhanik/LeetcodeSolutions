/*given a matrix we have to print it in spiral form*/

#include<bits/stdc++.h>
using namespace std;
vector<int>spiralMatrix(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=m-1;
    vector<int>spiral;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            spiral.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            spiral.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                spiral.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                spiral.push_back(matrix[i][left]);
            }
        }
        left++;
}
return spiral;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    vector<int>ans=spiralMatrix(matrix);
    for(int &num:ans){
        cout<<num<<" ";
    }
}