#include<bits/stdc++.h>
using namespace std;
/*
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>left(n,1),right(n,1);
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            left[i]=left[i-1]+1;
        }
    }

    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1]){
            right[i]=right[i+1]+1;
        }
    }

    vector<int>ans(n);
    for(int i=0;i<n;i++){
        ans[i]=max(left[i],right[i]);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    int cnt=accumulate(ans.begin(),ans.end(),0);
    cout<<"\n"<<cnt;
}*/
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=1,i=1;
    while(i<n){
        //flat surface
        if(arr[i]==arr[i-1]){
            sum+=1;i++;continue;
        }

        //for increasing slope
        int peak=1;
        while(i<n && arr[i]>arr[i-1]){
            peak+=1;
            sum+=peak;
            i++;
        }

        //ifdecreasing 
        int down=1;
        while(i<n && arr[i]<arr[i-1]){
            sum+=down;
            down+=1;
            i++;
        }

        if(down>peak){
            sum+=down-peak;
        }
    }
    cout<<endl;
    cout<<sum;
}