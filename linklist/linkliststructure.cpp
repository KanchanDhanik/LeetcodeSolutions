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

void printLL(Node*head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

Node* insertHead(Node*head,int val){
    Node*newn=new Node(val,head);
    return newn;
}

Node*deleteTail(Node*head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    delete temp->next;

    temp->next=NULL;
    return head;
}

bool search(Node*head,int val){
    Node*temp=head;
    while(temp!=NULL){
        if(temp->val==val){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int length(Node*head){
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
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

    cout << "\nInitial Linked List: ";
    printLL(head);
    cout << "\nLength: " << length(head) << "\n";

    // Test search
    int target;
    cout << "Enter value to search: ";
    cin >> target;
    if (search(head, target)) {
        cout << target << " found in the list.\n";
    } else {
        cout << target << " not found.\n";
    }

    // Test deleteTail
    head = deleteTail(head);
    cout << "\nAfter deleting tail: ";
    printLL(head);
    cout << "\nUpdated Length: " << length(head) << "\n";

    return 0;
}
