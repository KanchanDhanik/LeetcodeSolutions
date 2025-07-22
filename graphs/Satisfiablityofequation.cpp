#include<bits/stdc++.h>
using namespace std;
int findParent(int x,vector<int>&parent){
    if(parent[x]==x)return x;
    return parent[x]=findParent(parent[x],parent);
}

void unionByRank(int u,int v,vector<int>&parent,vector<int>&rank){
    int x=findParent(u,parent);
    int y=findParent(v,parent);
    if(x==y)return;
    if(rank[x]<rank[y]){
        parent[x]=y;
    }else if(rank[x]>rank[y]){
        parent[y]=x;
    }else{
        parent[x]=y;
        rank[x]++;
    }
}
bool isSatisfiable(vector<string>&equations){
    vector<int>parent(26);
    vector<int>rank(26,1);
    for(int i=0;i<26;i++){
        parent[i]=i;
    }
    for(auto &s:equations){
        if(s[1]=='='){
        char a=s[0];
        char b=s[3];
        unionByRank(a-'a',b-'a',parent,rank);
        }
    }
    for(auto &s:equations){
        if(s[1]=='!'){
        char a=s[0];
        char b=s[3];
        int x=findParent(a-'a',parent);
        int y=findParent(b-'a',parent);
        if(x==y)return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<string>equations(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        equations[i]=s;
    }

    bool check=isSatisfiable(equations);
    if(check==0)cout<<"NO";
    else cout<<"YES";
}