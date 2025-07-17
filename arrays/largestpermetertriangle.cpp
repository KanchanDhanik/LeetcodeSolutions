/* only check the condition where nums[i]<nums[i-1]+nums[i-2] i.e c<a+b
after sorting*/
#include<bits/stdc++.h>
using namespace std;
int findmaxPeri(vector<int>&nums){
    priority_queue<int>pq(nums.begin(),nums.end());

    while(pq.size()>=3){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int c=pq.top();
        pq.pop();

        if(a<(c+b)){
            return (a+b+c);
        }
        pq.push(b);
        pq.push(c);
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

   /* sort(nums.begin(),nums.end());
    for(int i=n-1;i>=2;i--){
        if(nums[i]<(nums[i-1]+nums[i-2])){
            cout<<(nums[i]+nums[i-1]+nums[i-2]);
        }
    }*/
   int ans=findmaxPeri(nums);
   cout<<ans;
   return 0;
}