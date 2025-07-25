#include<bits/stdc++.h>
using namespace std;

class Myqueue{
public:
stack<int>input;
stack<int>output;
int peekele=-1;
void push(int x){
    if(input.empty()){
        peekele=x;
    }
    input.push(x);
}
int peek(){
    if(output.empty()){
        return peekele;
    }
    return output.top();
}
//amortaized O(1)
int pop(){
    if(output.empty()){
        while(!input.empty()){//n
            output.push(input.top());
            input.pop();
        }
    }
    int val=output.top();//1
    output.pop();
    return val;
}
bool isEmpty(){
    return (input.empty() && output.empty());
}
};
int main(){
Myqueue q;
q.push(1);
q.push(2);
q.push(3);
cout<<q.peek()<<endl;
cout<<q.pop()<<endl;
cout<<q.pop()<<endl;
cout<<q.pop()<<endl;
cout<<q.isEmpty()<<endl;

}