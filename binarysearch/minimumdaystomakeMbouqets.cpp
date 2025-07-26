#include<bits/stdc++.h>
using namespace std;

bool canmake(vector<int>&arr,int m,int k,int day){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=day){
            cnt++;
            if(cnt==k){
                cnt=0;
                m--;
                if(m==0){
                    return true;
                }
            }
        }else{
            cnt=0;
        }
    }
    return false;
}

int minNoOfdaystomakeMbouquets(vector<int>&arr,int m,int k){
    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    int res=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canmake(arr,m,k,mid)){
            res=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int>flowers(n);
    for(int i=0;i<n;i++){
        cin>>flowers[i];
    }
    int m,k;
    cin>>m>>k;
    int ans=minNoOfdaystomakeMbouquets(flowers,m,k);
    cout<<ans;
}