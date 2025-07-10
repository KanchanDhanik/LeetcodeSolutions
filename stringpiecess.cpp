/*Given string written no of ways it can be cut into pieces with same chars*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>freq(26,0);
    int ans=0;
    for(int i=0;i<n;i++){
        freq[s[i]-'a']++;
        ans=freq[s[i]-'a'];
    }
    for(int i=0;i<26;i++){
        ans=gcd(freq[i],ans);
    }
    cout<<ans<<endl;
    return 0;
    }