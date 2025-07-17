/* Given an array nums we have to find if there exits three num ad nums[i]<num[j]<num[k] 
&&& i<j<k*/
#include<bits/stdc++.h>
using namespace std;

bool isIncreasingTriplet(vector<int>&nums){
    int num1=INT_MAX;
    int num2=INT_MAX;
    for(int num:nums){
        if(num<=num1){  
            num1=num;
        }else if(num<=num2){
            num2=num;
        }else{
            return true;
        }
    }
    return false;    
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool ans=isIncreasingTriplet(arr);
    cout<<ans;
    return 0;
}    