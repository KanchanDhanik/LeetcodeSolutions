#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>&temp,unordered_set<int>&st,vector<vector<int>>&res,vector<int>&arr){
    if(temp.size()==arr.size()){
        res.push_back(temp);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(st.find(arr[i])==st.end()){
            st.insert(arr[i]);
            temp.push_back(arr[i]);
            helper(temp,st,res,arr);
            temp.pop_back();
            st.erase(arr[i]);
        }
    }
}
vector<vector<int>>findpermu(vector<int>&arr){
    vector<vector<int>>res;
    unordered_set<int>st;
    vector<int>temp;
    helper(temp,st,res,arr);
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>res=findpermu(arr);
    cout<<endl;
    for(auto &v:res){
        for(auto &num:v){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}