#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt5=0;
    int cnt10=0;
    int cnt20=0;
    bool flag=true;
    for(int i=0;i<n;i++){
        if(arr[i]==5){
            cnt5++;
        }else if(arr[i]==10){
            if(cnt5>0){
                cnt5--;
            }else{
                flag=false;
                break;
            }
            cnt10++;
        }else{
            if(cnt5>=3){
                cnt5-=3;
            }else if(cnt5<3 && cnt10>0 && cnt5>1){
                cnt5--;
                cnt10--;
            }else{
                flag=false;
                break;
            }
            cnt20++;
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}