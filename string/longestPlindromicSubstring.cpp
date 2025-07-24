#include<bits/stdc++.h>
using namespace std;


string expandAroundcenter(string s,int c1,int c2){
    int l=c1,r=c2;
    int n=s.length();
    while(l>=0 && r<=n-1 &&s[l]==s[r]){
        l--;
        r++;
    }

    return s.substr(l+1,r-l-1);
}


string longestPalin(string s){
    int n=s.length();
    if(n==0)return "";
    string longest=s.substr(0,1);
    for(int i=0;i<n-1;i++){
        string p1=expandAroundcenter(s,i,i);
        if(p1.length()>longest.length()){
            longest=p1;
        }

        string p2=expandAroundcenter(s,i,i+1);
        if(p2.length()>longest.length()){
            longest=p2;
        }
    }
    return longest;
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
   /* vector<vector<int>>dp(n,vector<int>(n,0));
    int maxlen=1;
    int start=0;
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            start=i;
            maxlen=2;
        }
    }
    for(int len=3;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
                if(len>maxlen){
                    maxlen=len;
                    start=i;
                }
            }
        }
    }*/
   string longest=longestPalin(s);
    cout<<longest;
}