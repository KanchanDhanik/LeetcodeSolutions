#include<bits/stdc++.h>
using namespace std;


bool isIsomorphic(string s,string t){
    if(s.size()!=t.size()) return false;
    unordered_map<char,char> mp1,mp2;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(mp1.find(s[i])!=mp1.end() && mp1[s[i]]!=t[i]){
            return false;
        }else if(mp2.find(t[i])!=mp2.end() && mp2[t[i]]!=s[i]){
            return false;
        }else{
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
    }
    return true;
}
int main(){
    string s,t;
    cin>>s;
    cin>>t;
    if(isIsomorphic(s,t)){
        cout<<"YES they are isomorphic string"<<endl;
    }else{
        cout<<"NO they are not isomorphic string"<<endl;
    }
}