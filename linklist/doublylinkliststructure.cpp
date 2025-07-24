#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node*next;
    Node*back;
    Node(int val){
        this->val=val;
        next=NULL;
        back=NULL;
    }
    Node(int val,Node*next,Node*back){
        this->val=val;
        this->next=next;
        this->back=back;
    }
};

Node*insertAtEnd(int val,Node*head){
    Node*newNode=new Node(val);

    if(head==nullptr){
        return newNode;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->back=temp;
    return head;
}



Node*deletetail(Node*head){
    if(head==nullptr||head->next==nullptr){
        return nullptr;
    }

    Node*temp=head;

    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next->back=NULL;
    delete temp->next;
    temp->next=NULL;
    return head;
}

Node*deleteHead(Node*head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node*newhead=head->next;
    newhead->back=NULL;
    head->next=nullptr;
    delete head;
    return newhead;
}

Node*reverseDll(Node*head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    Node*prev=NULL;
    Node*curr=head;
    while(curr!=NULL){
        prev=curr->back;
        curr->back=curr->next;
        curr->next=prev;
        curr=curr->back;
    }
    return prev->back;
}

int length(Node*head){
    Node*temp=head;
    if(head==nullptr)return 0;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
void print(Node*head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Empty list.\n";
        return 0;
    }

    cout << "Enter the head value: ";
    int h;
    cin >> h;
    Node* head = new Node(h);
    Node* prev = head;

    cout << "Enter " << n - 1 << " more values:\n";
    for (int i = 0; i < n - 1; i++) {
        int val;
        cin >> val;
        Node* temp = new Node(val, nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    cout << "\nInitial List: ";
    print(head);
    cout << "\nLength: " << length(head) << "\n";

    // Delete tail
    head = deletetail(head);
    cout << "\nAfter deleting tail: ";
    print(head);
    cout << "\nLength: " << length(head) << "\n";

    // Delete head
    head = deleteHead(head);
    cout << "\nAfter deleting head: ";
    print(head);
    cout << "\nLength: " << length(head) << "\n";

    // Reverse DLL
    head = reverseDll(head);
    cout << "\nAfter reversing list: ";
    print(head);
    cout << "\nLength: " << length(head) << "\n";

    return 0;
}
