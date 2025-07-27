#include<bits/stdc++.h>
using namespace std;
int numSubmatrixSumTarget(vector<vector<int>>&mat,int target){
    int rows=mat.size();
    int cols=mat[0].size();


    //step1:take cumulate sum row wise
    for(int row=0;row<rows;row++){
        for(int col=1;col<cols;col++){
            mat[row][col]+=mat[row][col-1];
        }
    }

    //now we need to find no of sub matrices with sum==target -downwards(direction)
    int res=0;
    for(int startCol=0;startCol<cols;startCol++){
        for(int j=startCol;j<cols;j++){
            unordered_map<int,int>mpp;
            mpp[0]=1;
            int currsum=0;
            for(int row=0;row<rows;row++){
                currsum+=mat[row][j]-(startCol>0?mat[row][startCol-1]:0);
                if(mpp.find(currsum-target)!=mpp.end()){
                    res+=mpp[currsum-target];
                }
                mpp[currsum]++;
            }
        }
    }
    return res;
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int target;
    cin>>target;
    int k=numSubmatrixSumTarget(mat,target);
    cout<<k;
}