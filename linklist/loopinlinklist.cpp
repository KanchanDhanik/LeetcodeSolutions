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

bool detectloop(Node*head){
    Node*slow=head;
    Node*fast=head;
    if(head==nullptr ||fast==nullptr)return false;
    
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

Node*startofLoop(Node*head){
    if(head==nullptr ||head->next==nullptr)return head;
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int lengthofloop(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    int cnt=1;
    slow=slow->next;
    while(slow!=fast){
        cnt++;
        slow=slow->next;
    }
    return cnt;
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

    // Optionally create a loop for testing
    char choice;
    cout << "Do you want to create a loop? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int pos;
        cout << "Enter position (0-indexed) where tail connects: ";
        cin >> pos;

        Node* loopPoint = head;
        for (int i = 0; i < pos && loopPoint != nullptr; i++) {
            loopPoint = loopPoint->next;
        }

        if (loopPoint == nullptr) {
            cout << "Invalid position. No loop created.\n";
        } else {
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = loopPoint; // Creates the loop
            cout << "Loop created at node with value: " << loopPoint->val << "\n";
        }
    }

    // Detect loop
    if (detectloop(head)) {
        cout << "\n Loop detected in the linked list!\n";
    } else {
        cout << "\n No loop detected.\n";
    }

    Node*loopstart=startofLoop(head);
    if(loopstart!=nullptr)
    {
        cout<<"Loop starts at node with value: "<<loopstart->val<<endl;
    }
    int length=lengthofloop(head);
    if(length>0)
    {
        cout<<"Length of loop: "<<length<<endl;
    }

    return 0;
}

