#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int i=0;
    int res=0;
    while(i<n && s[i]==' '){
        i++;
    }

    int sign=1;
    if(s[i]=='+' ||s[i]=='-'){
        if(s[i]=='-'){
            sign=-1;
        }
        i++;
    }

    while(i<n){
        if(!isdigit(s[i])){
            break;
        }
        int digit=s[i]-'0';

        if(res>(INT_MAX-digit)/10){
            cout<<(sign==-1)?INT_MIN:INT_MAX;
            break;
        }
        res=res*10+digit;
        i++;
    }
    int ans=res*sign;
    cout<<ans;
}