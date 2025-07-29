#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>meetings(n);
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        meetings[i]={start,end};
    }
    sort(meetings.begin(),meetings.end(),[](const auto &a ,const auto &b){
        return a.second<b.second;
    });
    vector<int>ans;
    ans.push_back(1);
    int lastfinishTime=meetings[0].second;
    for(int i=1;i<n;i++){
        if(meetings[i].first>=lastfinishTime){
            ans.push_back(i+1);
            lastfinishTime=meetings[i].second;
        }
    }
    for(int &it:ans){
        cout<<it<<" ";
    }
}