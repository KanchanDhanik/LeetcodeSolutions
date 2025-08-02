#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int maxlen=dp[n][m];
    int i=n;
    int j=m;
    string ans="";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans=s1[i-1]+ans;
            maxlen--;
            i--;
            j--;
        }else if(s1[i-1]>s2[j-1]){
            i--;
        }else{
            j--;
        }
    }
    cout<<ans<<endl;
}