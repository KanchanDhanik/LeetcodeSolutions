#include<bits/stdc++.h>
using namespace std;
void generatehelper(string s,vector<string>&ans,int n){
    if(s.size()==n){
        ans.push_back(s);
        return;
    }
    //we have two options either take bit 0 ot bit 1
    //for bit 0 there is no rule so we simple add it to temp
    generatehelper(s+"0",ans,n);
    //we need to pop the first inserted bit also  before trying other
    //but for one we only include it id the prev ele is not one
    if(s.back()!='1'){
        generatehelper(s+"1",ans,n);
    }
}
vector<string>generate(int n){
    string temp;
    vector<string>ans;
    generatehelper(temp,ans,n);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string>ans=generate(n);
    for(auto i:ans){
        cout<<i<<endl;
    }
}