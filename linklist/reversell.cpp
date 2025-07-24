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




Node*insertAtLast(Node*head,int val){
    Node*newn=new Node(val);
    if(head==nullptr){
        return newn;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newn;
    return head;
}

Node*reversell(Node*head){
    Node*prev=nullptr;;
    Node*curr=head;
    while(curr!=NULL){
        Node*nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked list is empty.\n";
        return 0;
    }

    Node* head = nullptr;
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        head = insertAtLast(head, val);
    }

    // Print original list
    cout << "\nOriginal Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    // Reverse the list
    head = reversell(head);
    cout << "\nReversed Linked List: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << "\n";
    return 0;
}
