#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    int maxsum=0;
    int start=-1;
    int end=-1;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>maxsum){
            maxsum=sum;
            end=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<maxsum;
    cout<<endl;
     cout << "The subarray is: [";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << "]";
    
}