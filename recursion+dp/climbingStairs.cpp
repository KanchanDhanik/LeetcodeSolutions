
/*Recursion
int ways(int n){
if(n<0)return 0;
    if(n==0){
        return 1;
    }
    //two options either take one step or two step;
    int one=ways(n-1);
    int two=ways(n-2);
    return (one+two);
}*/

//Memoization
/*int ways(int n,vector<int>&dp){
    if(n<0)return 0;
    if(n==0){
        return 1;
        }
        if(dp[n]!=-1)return dp[n];
        //two options either take one step or two step;
        int one=ways(n-1,dp);
        int two=ways(n-2,dp);
        return dp[n]=one+two;
        }
*/
//Tabulation
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}

