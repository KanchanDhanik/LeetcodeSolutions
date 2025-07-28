#include<bits/stdc++.h>
using namespace std;
 vector<vector<string>>ans;


 bool isValid(vector<string>&board,int row,int col){

    //row upward
    for(int i=row-1;i>=0;i--){
        if(board[i][col]=='Q')return false;
    }
    //for left diagoals check
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q')return false;
    }

    //for right diagonal;
    for(int i=row-1,j=col+1;i>=0 && j>=0 ;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
 }
 void solve(vector<string>&board,int i){
    if(i==board.size()){
        ans.push_back(board);
        return;
    }
    for(int col=0;col<board.size();col++){
        if(isValid(board,i,col)){
            board[i][col]='Q';
            solve(board,i+1);
            board[i][col]='.';
        }
    }
 }
vector<vector<string>>nQueens(int n){
    vector<string>board(n,string(n,'.'));
    solve(board,0);
    return ans;
}
int main(){
    int n;
    cin>>n;
   ans=nQueens(n);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<endl;
            }
            cout<<endl;
        }
}