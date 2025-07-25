#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    if(ch=='^')return 3;
    if(ch=='*'||ch=='/')return 2;
    if(ch=='+'||ch=='-')return 1;
    return -1;
}
string infixtopostfix(string infix){
    
    string postfix="";
    stack<char>st;
    for(char &ch:infix){
        //if it is a operand
        if((ch>='a' && ch<='z')|| (ch>='A'&& ch<='Z') || (ch>='0' && ch<='9')){
            postfix+=ch;
        }else if(ch=='('){
            st.push(ch);
        }else if(ch==')'){
            while(!st.empty() && st.top()!='('){
                postfix+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }else{
            while(!st.empty() && precedence(ch)<=precedence(st.top())){
                postfix+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }
    return postfix;
}
string infixtoprefix(string infix){
    reverse(infix.begin(),infix.end());

    for(char &ch:infix){
        if(ch=='(')ch=')';
        else if(ch==')')ch='(';
    }

    string postfix=infixtopostfix(infix);
    reverse(postfix.begin(),postfix.end());
    return postfix;
}
int main(){
    string infix;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    string prefix=infixtoprefix(infix);
    cout<<"Prefix expression: "<<prefix<<endl;
}
