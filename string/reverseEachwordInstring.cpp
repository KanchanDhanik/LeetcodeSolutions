#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    cout<<endl;
    cout<<"ORIGINAL STRING : "<<s;
    reverse(s.begin(),s.end());
    cout<<endl;
    int n=s.length();
    int i=0;
    int left=0,right=0;
    while(i<n){
        while(i==' ' && i<n)i++;
        if(i==n)break;
        while(s[i]!=' ' && i<n){
            s[right++]=s[i++];
        }
        reverse(s.begin()+left,s.begin()+right);
        s[right++]=' ';
        left=right;
        i++;
    }
    cout<<"REVERSE STRING "<<s;
}