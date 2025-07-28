#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>children(n);
    for(int i=0;i<n;i++){
        cin>>children[i];
    }
    vector<int>cookies(m);
    for(int j=0;j<m;j++){
        cin>>cookies[j];
    }
    sort(children.begin(),children.end());
    sort(cookies.begin(),cookies.end());
    int cnt=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(children[i]<=cookies[j]){
            i++;
            j++;
            cnt++;
        }else{
            j++;
        }
    }
    cout<<cnt;
}