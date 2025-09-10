#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int upperbound(vector<int>&mat,int val){
    int low=0;
    int high=mat.size()-1;
    int ub=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mat[mid]<=val){
            low=mid+1;
            ub=low;
        }else{
            high=mid-1;
        }
    }
    return ub;
}
int blackbox(vector<vector<int>>&mat,int val){
    int cnt=0;
    int n=mat.size();
    for(int i=0;i<n;i++){
        cnt+=upperbound(mat[i],val);
    }
    return cnt;
}
int findMedian(vector<vector<int>>&mat,int n,int m){
    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0;i<n;i++){
        low=min(low,mat[i][0]);
        high=max(high,mat[i][m-1]);
    }

    int req=(n*m)/2;

    while(low<=high){
        int mid=low+(high-low)/2;
        int numlessthan=blackbox(mat,mid);
        if(numlessthan<=req){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    int median=findMedian(mat,n,m);
    cout<<endl;
    cout<<median;
    return 0;
}