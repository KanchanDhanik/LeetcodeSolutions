#include<bits/stdc++.h>
using namespace std;
struct Train{
int arival;
int departure;
};
int main(){
    int n;
    cin>>n;
    vector<Train>trains(n);
    for(int i=0;i<n;i++){
        cin>>trains[i].arival;
        cin>>trains[i].departure;
    }
    sort(trains.begin(),trains.end(),[](const Train &a,const Train &b){
        return a.departure<b.departure;
    });
    int lastdeptime=trains[0].departure;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(trains[i].arival>=lastdeptime){
            lastdeptime=trains[i].departure;
        }else{
            cnt++;
        }
    }
    cout<<cnt;
}