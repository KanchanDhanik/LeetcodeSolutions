#include<bits/stdc++.h>
using namespace std;
bool isoperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
        return true;
    }
    return false;
}
int main(){
    string prefix;
    cout<<"Enter the prefix expression: ";
    cin>>prefix;

    stack<string>st;

    for(int i=prefix.length()-1;i>=0;i--){
        char ch=prefix[i];
        if(isalnum(ch)){
            st.push(string(1,ch));
        }else if(isoperator(ch)){
            string op2=st.top();
            st.pop();
            string op1=st.top();
            st.pop();
            string expr=op2+op1+ch;
            st.push(expr);
        }
    }
    cout<<"Prefix expression is: "<<st.top()<<endl;
}