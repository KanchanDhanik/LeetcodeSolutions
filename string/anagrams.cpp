#include<bits/stdc++.h>
using namespace std;
bool areAnagrams(string s,string t){
    if(s.size()!=t.size())return false;
    unordered_map<char,int>mpp;
    for(char&ch:s){
        mpp[ch]++;
    }
    for(char &ch:t){
        mpp[ch]--;
    }
    for(auto &it:mpp){
        if(it.second!=0)return false;
    }
    return true;
}
int main(){
    string s,t;
    cin>>s>>t;
    bool check=areAnagrams(s,t);
    if(check){
        cout<<"valid anagrams";
    }else{
        cout<<"not valid anagrams";
    }
}