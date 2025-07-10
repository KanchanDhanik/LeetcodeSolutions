//3333. Find the Original Typed String II
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
int m=1e9+7;
//vector<vector<int>>dp;
/*long long helper(int i,int cnt,vector<int>freq,int k){
    if(i>=freq.size()){
        if(cnt<=k){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[i][cnt]!=-1)return dp[i][cnt];
    long long result=0;
    for(int take=1;take<=freq[i];take++){
        if(take+cnt<k){
            //if we can take the char we will can recursion for next char
            result=(result+helper(i+1,cnt+take,freq,k))%m;
        }else{
            break;
        }
    }
    return dp[i][cnt]=result;
}*/

/*Recursive solution
int possibleStringCount(string word, int k) {
        vector<int>freq;
        if(k>word.length())return 0;
        int cnt=1;
        for(int i=1;i<word.size();i++){
            if(word[i-1]==word[i]){
                cnt++;
            }else{
                freq.push_back(cnt);
                cnt=1;
            }
        }
        freq.push_back(cnt);

        int total=1;
        for(auto &num:freq){
            total=(total*num)%m;
        }
        int unique=freq.size();
        long long invalid=0;
        if(unique>=k){
            return total;
        }
            invalid=helper(0,0,freq,k);
            return (total-invalid);
    }
};*/
    int possibleStringCount(string word, int k) {
        if(k>word.length())return 0;
        vector<int>freq;
        int cnt=1;
        for(int i=1;i<word.length();i++){
            if(word[i-1]==word[i]){
                cnt++;
            }else{
                freq.push_back(cnt);
                cnt=1;
            }
        }
        freq.push_back(cnt);

        long long total=1;
        for(auto &num:freq){
            total=(total*num)%m;
        }
        int unique=freq.size();
        if(unique>=k){
            return total;
        }
        vector<vector<int>>dp(unique+1,vector<int>(k+1,0));
        long long invalid=0;
        for(int j=k-1;j>=0;j--){
            dp[unique][j]=1;
        }
        for(int i=unique-1;i>=0;i--){
             vector<int>prefix(k+1,0);
        for(int h=1;h<=k;h++){
            prefix[h]=(prefix[h-1]+dp[i+1][h-1])%m;
        }
            for(int j=k-1;j>=0;j--){
               int l=j+1;
               int r=j+freq[i];
               r=min(r,k-1);
               if(l<=r)
                dp[i][j]=(prefix[r+1]-prefix[l]+m)%m;
            }
        }
           // invalid=helper(0,0,freq,k);
            //return (total-invalid+m)%m;
            return (total-dp[0][0]+m)%m;
    }
};