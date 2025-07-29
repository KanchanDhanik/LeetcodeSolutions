#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>intervals(n);
    for(int i=0;i<n;i++){
        cin>>intervals[i].first;
        cin>>intervals[i].second;
    }

    sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
        return a.second<b.second;
    });
    vector<pair<int,int>>ans;
    ans.push_back(intervals[0]);
    int last=intervals[0].second;
    int cnt=0;
    for(int i=1;i<n;i++){
        if(intervals[i].first>=last){
            ans.push_back(intervals[i]);
            last=intervals[i].second;
        }else{
            cnt++;
        }
    }
    cout<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<cnt;
}