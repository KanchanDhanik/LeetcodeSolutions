#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
int val;
Node*left;
Node*right;

Node(int val){
    this->val=val;
    left=nullptr;
    right=nullptr;
}
Node(int val,Node*left,Node*right){
    this->val=val;
    this->left=left;
    this->right=right;
}
};
Node*flatten(Node*root){
    if(!root)return nullptr;
    Node*leftflatten=flatten(root->left);
    Node*rightflatten=flatten(root->right);
    root->left=nullptr;
    if(leftflatten){
        Node*temp=leftflatten;
        while(temp && temp->right){
            temp=temp->right;
        }
        temp->right=root;
        root->right=rightflatten;
        return leftflatten;
    }else{
        root->right=rightflatten;
        return root;
    }
}
int main() {
    /*
         Sample Tree:
              4
            /   \
           2     5
          / \     \
         1   3     6
    */

    Node* root = new Node(4,
                    new Node(2,
                        new Node(1),
                        new Node(3)
                    ),
                    new Node(5,
                        nullptr,
                        new Node(6)
                    )
                );

    Node* head = flatten(root);

    // Print the flattened list
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}


