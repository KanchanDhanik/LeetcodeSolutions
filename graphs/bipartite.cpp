#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<vector<int>>graph(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int>color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]!=-1)continue;
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:graph[u]){
                if(color[v]==color[u]){
                    cout<<"not a bipartite graph";
                    return 0;
                }
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }else continue;
            }
        }
    }
    cout<<"Bipartite Graph";
}