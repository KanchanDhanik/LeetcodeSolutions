/* we are given a 2d matrix of size nXm  we have to sort it diagonnaly in top to down manner 
eg if there is matrix  3 3 1 1  this will be converted to 1 1 1 1
                       2 2 1 2                            1 2 2 2
                       1 1 1 2                            1 2 3 3
*/  
/* so to do this we can find a relation ship that is common between that elements that is [i-j] for digonal elements is always same for that
particular diagonal and also [i+j] but in this case the downward diagonal is to be chosen  so we take it [i-j]

steps:
1: we will make a mapp and store key as [i-j] and elements of mat[i][j] in vector 
2: sort the vectors present in the map
3: collect the sorted result here if we will collect from starting we will encounter the same element in the vector
but if we collect from end then pop the last element we can find the full sorted soln */

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>sortDiagonally(vector<vector<int>>mat,int n,int m){
   //1: we will make a mapp and store key as [i-j] and elements of mat[i][j] in vector  
    unordered_map<int,vector<int>>mpp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mpp[i-j].push_back(mat[i][j]);
        }
    }
    //2: sort the vectors present in the map
    for(auto &v:mpp){
        sort(v.second.begin(),v.second.end());
    }
    //3: collect the sorted result here if we will collect from starting we will encounter the same element in the vector
//but if we collect from end then pop the last element we can find the full sorted soln 
   for(int i=n-1;i>=0;i--){
     for(int j=m-1;j>=0;j--){
        mat[i][j]=mpp[i-j].back();
        mpp[i-j].pop_back();
     }
  }
return mat;
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
    vector<vector<int>>sorted=sortDiagonally(mat,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<sorted[i][j]<<" ";
        }
        cout<<endl;
    }
}