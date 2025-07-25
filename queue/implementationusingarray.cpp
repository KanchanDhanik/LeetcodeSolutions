#include<bits/stdc++.h>
using namespace std;
class Q{
    int *arr;
    int start,end,currsize,maxsize;
    public:
    Q(){
        arr=new int[16];
        start=-1;
        end=-1;
        currsize=0;
    }
    Q(int maxsize){
        this->maxsize=maxsize;
        arr=new int[maxsize];
        start=-1;
        end=-1;
        currsize=0;
    }
    void push(int val){
        if(currsize==maxsize){
            cout<<"Queue is full"<<endl;
            exit(1);
        }
        if(end==-1){
            start=0;
            end=0;
        }else{
            end=(end+1)%maxsize;
        }
        arr[end]=val;
        cout<<"the elementr pushed is : "<<val<<endl;
        currsize++;
    }
    int pop(){
        if(start==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int val=arr[start];
        if(currsize==1){
            start=-1;
            end=-1;
        }else{
            start=(start+1)%maxsize;
        }
        currsize--;
        return val;
    }
    int front(){
        if(start==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            return arr[start];
        }
    }
    int size(){
        return currsize;
    }
};

int main() {
  Q q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.front() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.front() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;

  return 0;
}