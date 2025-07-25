#include<bits/stdc++.h>
using namespace std;
bool isoperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
        return true;
    }
    return false;
}
int main(){
    string postfix;
    cout<<"Enter the postfix expression: ";
    cin>>postfix;

    stack<string>st;

    for(char &ch:postfix){
        if(isalnum(ch)){
            st.push(string(1,ch));
        }else if(isoperator(ch)){
            string op2=st.top();
            st.pop();
            string op1=st.top();
            st.pop();
            string expr="("+op1+ch+op2+")";
            st.push(expr);
        }
    }
    cout<<"Infix expression is: "<<st.top()<<endl;
}