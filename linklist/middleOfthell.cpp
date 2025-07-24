#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val = val;
        next = NULL;
        }
    Node(int val,Node*next){
        this->val=val;
        this->next=next;
    }
};


Node* insertHead(Node*head,int val){
    Node*newn=new Node(val,head);
    return newn;
}


Node* middleNode(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty.\n";
        return 0;
    }

    int v;
    cout << "Enter head value: ";
    cin >> v;
    Node* head = new Node(v);

    cout << "Enter " << n - 1 << " more values:\n";
    for (int i = 0; i < n - 1; i++) {
        int val;
        cin >> val;
        head = insertHead(head, val);
    }

    Node*middle=middleNode(head);
    cout<<"Middle Node Value is "<<middle->val<<endl;
}