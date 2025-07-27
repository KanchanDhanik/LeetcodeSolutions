#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    vector<vector<int>>res;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        for(int j=i+1;j<n;j++){
        if(j>i+1 && arr[j]==arr[j-1])continue;
        int k=j+1;
        int l=n-1;
        while(k<l){
            int sum=arr[i]+arr[j]+arr[k]+arr[l];
            if(sum>target){
                l--;
            }else if(sum<target){
                k++;
            }else{
                res.push_back({arr[i],arr[j],arr[k],arr[l]});
                k++;
                l--;
                while(k<l && arr[k]==arr[k-1])k++;
                while(k<l &&arr[l]==arr[l+1])l--;
            }
        }
    }
    }
    for(auto&v:res){
        for(int&x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}