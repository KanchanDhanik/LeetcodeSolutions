#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>>res;
    for(int i=0;i<n;i++){
       if(i!=0 && arr[i]==arr[i-1])continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];

            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                res.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            while(j<k && arr[j]==arr[j-1])j++;
            while(j<k && arr[k]==arr[k+1])k--;
            }
        }
    }
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
