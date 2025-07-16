#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

void toLowerString(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    
    toLowerString(s1);
    toLowerString(s2);
    
    // Compare the strings
    if (s1<s2) {
        cout<<"-1"<<endl;
    } 
    else if(s1==s2) {
        cout<<"0"<<endl;
    } 
    else {
        cout<<"1"<<endl;
    }
    
    return 0;
}