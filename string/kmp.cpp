#include<bits/stdc++.h>
using namespace std;

vector<int>computelps(string&pattern){
    int m=pattern.size();
    vector<int>lps(m);
    lps[0]=0;
    int len=0;
    for(int i=1;i<m;i++){
        while(len>0 && pattern[i]!=pattern[len]){
            len=lps[len-1];
        }
        if(pattern[i]==pattern[len]){
            len++;
        }
        lps[i]=len;
    }
    return lps;
}
vector<int>kmp(string &text,string &pattern){
    int m=pattern.size();
    int n=text.size();
    int j=0;
    vector<int>lps=computelps(pattern);
    vector<int>matches;
    for(int i=0;i<n;i++){
        while(j>0 && pattern[j]!=text[i]){
            j=lps[j-1];
        }
        if(pattern[j]==text[i]){
            j++;
        }
        if(j==m){
            matches.push_back(i-m+1);
            j=lps[j-1];
        }
    }
    return matches;
}
int main(){
    string pattern,text;
    cin>>text>>pattern;
    vector<int>matches=kmp(text,pattern);
    cout<<endl;
    cout<<"pattern found at index : ";
    for(int&it:matches){
        cout<<it<<" ";
    }
}