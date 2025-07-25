#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

struct Node*front=nullptr;
struct Node*rear=nullptr;
class Q{
    public:
    int size=0;
    bool Empty(){
        if(front==nullptr){
            return true;
        }
        return false;
    }

    void Enqueue(int val){
        struct Node*ele=new Node(val);
        if(ele==nullptr){
            cout<<"Memory exhausted"<<endl;
            return;
        }
        if(front==nullptr){
            front=ele;
            rear=ele;
        }else{
            rear->next=ele;
            rear=ele;
        }
        cout<<val<<" Inserted into Queue "<<endl;
        size++;
    }
    int Dequeue(){
        if(Empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            int val=front->data;
            struct Node*temp=front;
            front=front->next;
            delete temp;
            size--;
            return val;
        }
    }
    int peek(){
        if(Empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
};
int main()
{
    Q Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    cout<<Q.Dequeue()<<"Removed From Queue"<<endl;
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.peek()<<endl;
    return 0;
}  