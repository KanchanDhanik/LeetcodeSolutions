#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        left=right=NULL;

    }
};

bool isIdentical(Node*root1,Node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }

    if(root1==NULL ||root2==NULL){
        return false;
    }


    return ((root1->val==root2->val) && isIdentical(root1->left,root2->left)
&& isIdentical(root1->right,root2->right));
}


int main() {
    // Node1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    
    if (isIdentical(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}