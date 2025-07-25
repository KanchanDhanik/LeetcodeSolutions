#include<bits/stdc++.h>
using namespace std;
class minStack{
stack<pair<int,int>>st;
public:
void push(int x){
    int min;
    if(st.empty()){
        min=x;
    }else{
        min=std::min(st.top().second,x);
    }
    st.push({x,min});
}
void pop(){
    st.pop();
}
int top(){
    return st.top().first;
}
int mini(){
    return st.top().second;
}
};
int main(){
    minStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(0);
    cout<<"minimum elemnet : "<<st.mini();
    st.pop();
    cout<<"minimum elemnet : "<<st.mini();
    return 0;
}