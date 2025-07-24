#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=0;
    string newstr="";
    for(char &ch:s){
        if(ch=='('){
            if(count>0){
                newstr+=ch;
            }
            count++;
        }else{
            count--;
            if(count>0){
                newstr+=ch;
            }
        }
    }
    cout<<"string after removinf outer bracket";
    cout<<newstr;
}