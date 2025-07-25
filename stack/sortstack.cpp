#include<bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>&st,int val){
    if(st.empty() || st.top()<=val){
        st.push(val);
        return;
    }
    int temp=st.top();
    st.pop();
    insertSorted(st,val);
    st.push(temp);
}
void sortStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    sortStack(st);
    insertSorted(st,temp);
}
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    cout << "Original Stack: ";
    printStack(st);

    sortStack(st);
    
    cout << "Sorted Stack: ";
    printStack(st);
}