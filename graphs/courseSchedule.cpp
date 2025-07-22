#include<bits/stdc++.h>
using namespace std;


vector<int>courseSdle(int n,vector<vector<int>>&pre){
    vector<vector<int>>adj(n);
    vector<int>inDegree(n,0);
    for(auto&V:pre){
        int a=V[0];
        int b=V[1];
        adj[b].push_back(a);
        inDegree[a]++;
    }

    queue<int>q;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(int &v:adj[u]){
            inDegree[v]--;
            if(inDegree[v]==0){
                q.push(v);
            }
        }
    }

    if(ans.size()==n)return ans;
    else return {};
}
int main(){
    int nCourses;
    cin>>nCourses;
    int n;
    cin>>n;
    vector<vector<int>>prerequisites;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        prerequisites.push_back({a,b});
    }

    vector<int>ans=courseSdle(nCourses,prerequisites);
    cout<<endl;
    for(int&it:ans){
        cout<<it<<" ";
    }
}