#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>flyodwarshell(int n,vector<vector<int>>edges){
    int n=edges.size();
    int m=edges[0].size();
    
    
    vector<vector<int>>dist(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=edges[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=1e9 && dist[k][j]!=1e9
                && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return dist;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>edges(n,vector<int>(n,1e9));
    for(int i=0;i<e;i++){
        int u,v,w;
        edges[u][v]=w;
    }
    int src;
    cin>>src;
    vector<vector<int>>dist=flyodwarshell(n,edges);
    cout<<endl;
    for(auto it:dist){
        for(auto d:it){
            cout<<d<<" ";
        }
        cout<<endl;
    }
}
