#include<bits/stdc++.h>
using namespace std;


int countoverlap(vector<vector<int>>&a,vector<vector<int>>&b,int ro,int co){
    int count=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int bi=i+ro;
            int bj=j+co;
            if(bi<0 ||bj<0 ||bi>=n || bj>=n)continue;
            if(a[i][j]==1 && b[bi][bj]==1){
                count++;
            }
        }
    }
    return count;
}
int largestOverlap(vector<vector<int>>&a,vector<vector<int>>&b){
    int n=a.size();
    int maxoverlap=0;
    for(int row_off=-n+1;row_off<n;row_off++){
        for(int col_off=-n+1;col_off<n;col_off++){
            int curroverlap=countoverlap(a,b,row_off,col_off);
            maxoverlap=max(maxoverlap,curroverlap);
    }
}
    return maxoverlap;
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr1(n,vector<int>(n));
    vector<vector<int>>arr2(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr2[i][j];
        }
    }

    int maxoverlap=largestOverlap(arr1,arr2);
    cout<<endl;
    cout<<maxoverlap;
    return 0;
    
}