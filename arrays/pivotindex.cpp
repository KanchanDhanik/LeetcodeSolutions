/* we have to find the pivot index where the leftside sum==rightside summ excluding that element*/
#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int>&arr,int n){
    int totalsum=accumulate(arr.begin(),arr.end(),0);
    int leftsum=0;
    int pivot=-1;
    for(int i=0;i<n;i++){
        if(leftsum==(totalsum-leftsum-arr[i])){
            pivot=i;
            break;
        }
        leftsum+=arr[i];
    }
    return pivot;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pivot=findPivot(arr,n);
    cout<<endl<<endl;
    cout<<pivot;
    return 0;
}