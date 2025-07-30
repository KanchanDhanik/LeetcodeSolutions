#include<bits/stdc++.h>
using namespace std;
int main(){
    //important  note to be known if we and two numbers the result <=the two numbers
    //so if we and the whole array the result would get smaller and smaller
    //the highest and we can get is the maximum element innthe arraya
    //then we only neend to find the len of continus max element 
    //as doing end will give us lower value than maxi if done with other ele
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int len=0;
    int maxlen=1;
    int maxi=*max_element(arr.begin(),arr.end());

    for(int&num:arr){
        if(num==maxi){
            len++;
            maxlen=max(maxlen,len);
        }else{
            len=0;
        }
    }
    cout<<maxlen;
}