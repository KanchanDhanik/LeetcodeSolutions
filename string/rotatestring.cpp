#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string goal;
    cin>>goal;
    string temp=s+s;
    if(temp.find(goal)!=string::npos){
        cout<<"string found by concatination method";
    }
    
}