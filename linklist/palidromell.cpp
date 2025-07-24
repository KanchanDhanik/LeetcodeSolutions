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

Node*findMiddle(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node*reversell(Node*head){
    Node*prev=NULL;
    Node*curr=head;
    while(curr!=NULL){
        Node*nextn=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextn;
    }
    return prev;
}

bool isPalindrome(Node*head){

    if(head==nullptr ||head->next==nullptr)return true;
    Node*mid=findMiddle(head);

    Node*newhead=reversell(mid->next);

    Node*temp1=head;
    Node*temp2=newhead;
    while(temp2!=NULL){
        if(temp1->val!=temp2->val){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    reversell(newhead);
    return true;   
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

    bool ispalin=isPalindrome(head);
    if(ispalin){
        cout<<"\nLinked list is a palindrome";
    }else{
        cout<<"\nLinked list is not a palindrome";
    }
}