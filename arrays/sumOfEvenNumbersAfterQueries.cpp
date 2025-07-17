/*given an array nums and queries which contain queries[i]=[val,index]
we have to apply query and afer that find the sum of even numbers in the nums array
store result after each query execution*/
#include<bits/stdc++.h>
using namespace std;


vector<int>findSumeven(vector<int>&nums,vector<vector<int>>&queries,int n){
    int sumEven=0;
    for(auto&num:nums){
        if(num%2==0){
            sumEven+=num;
        }
    }
    vector<int>ans;
    for(auto& q:queries){
        int val=q[0];
        int index=q[1];

        if(nums[index]%2==0)sumEven-=nums[index];

        int newVal=val+nums[index];
         nums[index]=newVal;
        if(newVal%2==0)sumEven+=newVal;
        ans.push_back(sumEven);
    }
    return ans;
}


int main(){
    int n;
    int q;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>q;
    vector<vector<int>>queries(q,vector<int>(2));
    for(int i=0;i<q;i++){
        for(int j=0;j<2;j++){
            cin>>queries[i][j];
        }
    }
    vector<int>ans=findSumeven(nums,queries,n);
    cout<<endl<<endl;
    for(int&num:ans){
        cout<<num<<" ";
    }
    return 0;
}