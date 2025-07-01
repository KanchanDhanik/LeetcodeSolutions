//Segment Tree basics 
//Build and RMQ template

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void build(int st[],vector<int>&nums,int i,int l,int r){
    if(l==r){
        st[i]=nums[l];
        return;
    }

    int mid=l+(r-l)/2;
    build(st,nums,2*i+1,l,mid);
    build(st,nums,2*i+2,mid+1,r);
    st[i]=min(st[2*i+1],st[2*i+2]);
}
int RMQ(int st[],vector<int>nums,int i,int low,int high,int l,int r){
    //no overlap lr low high or low high l r
    if(r<low || l>high){
        return INT_MAX;
    }
    //complete overlap low l r high
    if(low>=l && high<=r){
        return st[i];
    }

    //partial overlap
    int mid=low+(high-low)/2;
    int left=RMQ(st,nums,2*i+1,low,mid,l,r);
    int right=RMQ(st,nums,2*i+2,mid+1,high,l,r);
    return min(left,right);
}
void update(int st[],int i,int l,int r,int ind,int val){
    if(l==r){
        st[i]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(ind<=mid)update(st,i*2+1,l,mid,ind,val);
    else update(st,i*2+2,mid+1,r,ind,val);
    st[i]=min(st[2*i+1],st[2*i+2]);
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int *st=new int[4*n];
    build(st,nums,0,0,n-1);
    while(true){
    int type;
    cin>>type;
    if(type==1){
        int ind,val;
        cin>>ind>>val;
        update(st,0,0,n-1,ind,val);
        nums[ind]=val;
    }else{
        int l,r;
        cin>>l>>r;
        int minVal=RMQ(st,nums,0,0,n-1,l,r);
        cout<<minVal<<endl;
    }
}
    return 0;
}
