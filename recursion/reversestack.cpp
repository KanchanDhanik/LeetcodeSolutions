#include<bits/stdc++.h>
using namespace std;

void insertatbottom(stack<int>&st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int temp=st.top();
    st.pop();
    insertatbottom(st,ele);
    st.push(temp);
}
void reversest(stack<int>&st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    reversest(st);
    insertatbottom(st,temp);
}
int main(){
    stack<int>st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        st.push(val);
    }
    reversest(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}