#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();

    vector<string>substr;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            substr.push_back(s.substr(i,j-i+1));
        }
    }
    cout<<endl;
    cout<<"total no of substr : "<<substr.size();
    cout<<endl;
    for(string&sub:substr){
        cout<<sub<<"\n";
    }
}