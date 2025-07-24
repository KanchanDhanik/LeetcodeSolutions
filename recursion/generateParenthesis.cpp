#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    int count=0;
    for(char &ch:s){
        if(ch=='('){
            count++;
        }else{
            count--;
        }
        if(count<0)return false;
    }
    return count==0;
}
void helper(int open,int close,int n,vector<string>&valid,string&curr){
    if(curr.length()==2*n){
            valid.push_back(curr);
        return;
    }
    if(open<n){
    curr.push_back('(');
    helper(open+1,close,n,valid,curr);
    curr.pop_back();
    }
    if(close<open){
    curr.push_back(')');
    helper(open,close+1,n,valid,curr);
    curr.pop_back();
    }
}
vector<string>generateparen(int n){
    vector<string>valid;
    string curr="";
    helper(0,0,n,valid,curr);
    return valid;
}
int main(){
    int n;
    cin>>n;
    vector<string>ans=generateparen(n);
    for(string &s:ans){
        cout<<s<<endl;
    }
}