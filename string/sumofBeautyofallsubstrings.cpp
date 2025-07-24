#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int sum=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int>mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;

            int maxi=INT_MIN;
            int mini=INT_MAX;

            for(auto &it:mpp){
                maxi=max(maxi,it.second);
                mini=min(mini,it.second);
            }
            sum+=(maxi-mini);
        }
    }
    cout<<sum;
}