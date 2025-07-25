#include<bits/stdc++.h>
using namespace std;
class stackImp{
    public:
    int size;
    int top;
    int *st;
    stackImp(){
        size=1000;
        top=-1;
        st=new int[size];
    }
    void push(int val){
        if(top>=size){
            cout<<"stack is full"<<endl;
            return;
        }
        top++;
        st[top]=val;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        int ele=st[top];
        top--;
        return ele;
    }
    int Size(){
        return top+1;
    }
    int Top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return st[top];
    }
};
int main(){
    stackImp s;
    s.push(9);
    s.push(8);
    s.push(7);
    cout<<"top of stack :"<<s.Top()<<endl;
    cout<<"size of stack :"<<s.Size()<<endl;
    cout<<"elment deleted : "<<s.pop()<<endl;
    cout<<"size of stack :"<<s.Size()<<endl;
    cout<<"top of stack :"<<s.Top()<<endl;
}