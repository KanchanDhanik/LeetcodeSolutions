#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            if(i!=j){
                arr[i]=arr[j];
                arr[j]=0;
            }
            i++;
        }
    }
    cout<<endl;
    for(int&it:arr){
        cout<<it<<" ";
    }
}