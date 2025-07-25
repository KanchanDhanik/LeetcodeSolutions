#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    if(ch=='^')return 3;
    if(ch=='*'||ch=='/')return 2;
    if(ch=='+'||ch=='-')return 1;
    return -1;
}
int main(){
    stack<char>st;
    string infix;
    cout<<"Enter the infix expression: ";
    cin>>infix;

    string postfix="";

    for(char &ch:infix){
        //if it is a operand
        if((ch>='a' && ch<='z')|| (ch>='A'&& ch<='Z') || (ch>='0' && ch<='9')){
            postfix+=ch;
        }else if(ch=='('){
            st.push(ch);
        }else if(ch==')'){
            while(st.top()!='('){
                postfix+=st.top();
                st.pop();
            }
            st.pop();
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
    cout<<"Postfix expression: "<<postfix<<endl;

}