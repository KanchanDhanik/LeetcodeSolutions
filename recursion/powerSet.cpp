#include<bits/stdc++.h>
using namespace std;
void helper(string s,int i,vector<string>&subset,string&curr){
    if(i>=s.size()){
        if(curr!=""){
            subset.push_back(curr);
        }
        return;
    }
    curr.push_back(s[i]);
    helper(s,i+1,subset,curr);
    curr.pop_back();
    helper(s,i+1,subset,curr);
}
int main(){
    string s;
    cin>>s;
    vector<string>subset;
    string curr="";
    helper(s,0,subset,curr);
    sort(subset.begin(),subset.end());
    for(string&it:subset){
        cout<<it<<" ";
    }
}