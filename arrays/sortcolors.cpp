/*given three different colors 0,1,2 we have to sort them*/
/* we will be using here an algorithm named "DUTCH NATIONAL FLAG ALGO" in which we consider that from
0 to low-1 there are 0's from low to mid there are 1's and from mid+1 to high there are 2's
keeping intial position of low=0,mid=0,high=n-1*/
#include<bits/stdc++.h>
using namespace std;
void helper(vector<int>&nums,int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<endl<<endl;
    helper(nums,n);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}