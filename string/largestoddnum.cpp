#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int right=n-1;
    for(int i=right;i>=0;i--){
        if((s[i]-'0')&1){
            cout<<s.substr(0,i+1);
            break;
        }
    }
}