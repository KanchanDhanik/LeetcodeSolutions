#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int dup=-1;
    int miss=-1;

    for(int i=0;i<n;i++){
        if(nums[nums[i]-1]<0){
            dup=nums[i];
        }else{
            nums[nums[i]-1]*=(-1);
        }
    }

    for(int i=0;i<n;i++){
        if(nums[i]>0){
            miss=i+1;
        }
    }

    cout<<dup<<" "<<miss;
}