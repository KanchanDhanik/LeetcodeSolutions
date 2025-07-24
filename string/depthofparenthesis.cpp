#include<bits/stdc++.h>
using namespace std;
    int maxDepth(string s) {
        int cnt=0;
       int maxcnt=0;
        for(char&ch:s){
            if(ch=='('){
                cnt++;
                maxcnt=max(cnt,maxcnt);
            }else if(ch==')' && cnt>0){
                cnt--;
            }
        }
        return maxcnt;
    }
int main(){
    string s;
    cin>>s;
    int len=maxDepth(s);
    cout<<len;
}