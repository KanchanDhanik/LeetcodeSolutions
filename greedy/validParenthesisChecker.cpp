#include<bits/stdc++.h>
using namespace std;

/*bool checker(string s,int i,int opencnt,int closecnt){
    if(i==s.length()){
        if(opencnt==closecnt){
            return true;
        }
        return false;
    }
    if(closecnt>opencnt)return false;
    bool ans=false;
    if(s[i]=='('){
        ans=checker(s,i+1,opencnt+1,closecnt);
    }else if(s[i]=='*'){
        bool open=checker(s,i+1,opencnt+1,closecnt);
        bool close=checker(s,i+1,opencnt,closecnt+1);
        bool leave=checker(s,i+1,opencnt,closecnt);
        ans=open||close||leave;
    }else{
        if(closecnt<opencnt){
            ans=checker(s,i+1,opencnt,closecnt+1);
        }else{
            ans=false;
        }
    }
    return ans;
}*/

bool checker(string s){
    int max=0;
    int min=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            min+=1;
            max+=1;
        }else if(s[i]==')'){
            min-=1;
            max-=1;
        }else{
            min-=1;
            max+=1;
        }
        if(min<0)min=0;
        if(max<0)return false;
    }
    return (min==0);
}

int main(){
    string s;
    cin>>s;
    bool flag=checker(s);
    if(flag){
        cout<<"valid"<<endl;
    }else{
        cout<<"invalid"<<endl;
    }
}