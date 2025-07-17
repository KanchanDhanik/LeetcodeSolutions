/*An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array
Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.
.*/
#include<bits/stdc++.h>
using namespace std;
vector<int>findOriginal(vector<int>&changed,int n){
    if(n&1)return {};
    sort(changed.begin(),changed.end());
    unordered_map<int,int>mpp;
    for(auto &num:changed){
        mpp[num]++;
    }

    vector<int>ans;
    for(int &num:changed){
        int twice=2*num;

        if(mpp[num]==0)continue;

        if(mpp.find(twice)==mpp.end() || mpp[twice]==0){
            return {};
        }
        mpp[num]--;
        mpp[twice]--;
        ans.push_back(num);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>changed(n);
    for(int i=0;i<n;i++){
        cin>>changed[i];
    }
    vector<int>original=findOriginal(changed,n);
    cout<<endl<<endl;
    for(int num:original){
        cout<<num<<" ";
    }
    return 0;
}