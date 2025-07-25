#include<iostream>
using namespace std;
struct stackNode{
    int data;
    stackNode* next;
    int size;
    stackNode(int val){
        data=val;
        next=NULL;
    }
};

struct stack{
    stackNode*top;
    int size;
    stack(){
        size=0;
        top=NULL;
    }
    void push(int x){
        stackNode*ele=new stackNode(x);
        ele->next=top;
        top=ele;
        cout<<"element pushed "<<endl;
        size++;
    }
    int pop(){
        if(top==NULL){
            cout<<"stack is empty";
        }
        int val=top->data;
        stackNode*temp=top;
        top=top->next;
        delete temp;
        size--;
        return val;
    }
    int stacksize(){
        return size;
    }
    bool stackIsEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
    int stackPeek(){
        if(top==NULL){
            return -1;
        }
        return top->data;
    }
    void print(){
        stackNode*temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main() {
  stack s;
  s.push(10);
  cout << "Element popped: " << s.pop() << "\n";
  cout << "Stack size: " << s.stacksize() << "\n";
  cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
  cout << "stack's top element: " << s.stackPeek() << "\n";
  return 0;
}

