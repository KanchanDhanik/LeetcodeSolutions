#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node*left;
Node*right;
Node(int val){
    data=val;
    left=NULL;
    right=NULL;
}
};
vector<vector<int>>preInPostTraversal(struct Node*root){
    vector<int>pre,in,post;
    if(root==NULL){
        return {};
    }
    stack<pair<struct Node*,int>>st;
    st.push({root,1});

    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);

            it.second=2;

            st.push(it);

            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }else if(it.second==2){
            in.push_back(it.first->data);

            it.second=3;
            st.push(it);

            if(it.first->right)st.push({it.first->right,1});

        }else{
            post.push_back(it.first->data);
        }
    }
    return {pre,in,post};
}
int main(){
struct  Node*root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->right->left=new Node(6);
root->right->right=new Node(7);
 vector<int> pre, in, post;
 vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}