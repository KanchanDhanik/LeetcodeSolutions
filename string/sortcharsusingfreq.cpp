#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    unordered_map<char,int>mpp;
    for(char&ch:s){
        mpp[ch]++;
    }
    vector<pair<char,int>>freq(mpp.begin(),mpp.end());
    sort(freq.begin(),freq.end(),[](const auto &a,const auto &b){
        return a.second>b.second;
    });
    string ans="";
    cout<<endl;
    for(auto &it:freq){
        ans+=string(it.second,it.first);
    }
    cout<<"string after sorting : "<<ans<<endl;
}