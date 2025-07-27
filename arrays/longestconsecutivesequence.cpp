#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_set<int>st;
    for(int &num:arr){
        st.insert(num);
    }
    int maxlen=0;
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int x=it;
            int cnt=1;
            while(st.find(x+1)!=st.end()){
                x++;
                cnt++;
            }
            maxlen=max(maxlen,cnt);
        }
    }
    cout<<maxlen;
}