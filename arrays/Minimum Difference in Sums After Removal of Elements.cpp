/*Given a zero indexed array of nums consisting of 3*n elements
we have to minimize the  difference of left part of sum of array -right partof the array
after removal of n elments in such a way that the resulting difference is minimum

so here we observe three things
1: to minimize the difference(left-right)left sumshould be as minimumas possible and right
side sum should be as maximum as possible
as the array size is of 3 n so after removing n elemnets there will be 
equal elements in right and left as n-n 

2:while keeping the n size we can use the minHeap and maxheap for making the left sum as small as posssible for n elements and 
right sum as max as possible for remainng n elments 

3:after we have created leftminSum array and RightminSum  array
we can find the  min diff of leftpart and right part by traversing from n-1 to 2*n-1;


*/

#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<int>&nums){
    int N=nums.size();
    int n=N/3;

    vector<long long>leftMinSum(N,0);
    long long leftsum=0;
    //for leftsum we will traverse from 0 to 2*n-1 as we have to leave
    //n elements for the right part

    priority_queue<int>maxH;
    for(int i=0;i<2*n;i++){
        maxH.push(nums[i]);
        leftsum+=nums[i];

        if(maxH.size()>n){
            leftsum-=maxH.top();
            maxH.pop();
        }
        leftMinSum[i]=leftsum;
    }
    //for rightsum we will traverse from N-1 to n as we have to
    //leave n elements for the left part
    priority_queue<int,vector<int>,greater<int>>minH;
    vector<long long>rightMaxSum(N,0);
    long long rightsum=0;
    for(int i=N-1;i>=n;i--){
        minH.push(nums[i]);
        rightsum+=nums[i];

        if(minH.size()>n){
            rightsum-=minH.top();
            minH.pop();
        }
        rightMaxSum[i]=rightsum;
    }

    //now we have to calculate diff of sum b/w the right part and left part
    long long mindiff=LLONG_MAX;
    for(int i=n-1;i<2*n;i++){
        mindiff=min(mindiff,leftMinSum[i]-rightMaxSum[i+1]);
    }
    return mindiff;
}
int main(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(int i=0;i<N;i++){
        cin>>nums[i];
    }
    long long mindiff= findMinDiff(nums);
    cout<<mindiff<<endl;
    return 0;
}