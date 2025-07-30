#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //right to left traversal
    //vector<int>(32,-1)to store when is he ith bit is set by which index element
    vector<int>bit(32,-1);
    //Bit[j]=i,it means jth bit can be set via element at index i in nums
    vector<int>ans(n);

    for(int i=n-1;i>=0;i--){

        //nums[i]=binary rep

        int endInd=i;
        for(int j=0;j<32;j++){
            if(!(arr[i]& (1<<j))){
                if(bit[j]!=-1){
                    endInd=max(endInd,bit[j]);
                }
                }else{
                    bit[j]=i;
            }
        }
        ans[i]=endInd-i+1;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}