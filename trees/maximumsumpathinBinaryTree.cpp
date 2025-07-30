#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int maxPathSumUtil(Node*root,int& maxi){
    if(root==nullptr){
        return 0;
    }

    int leftMaxPath=max(0,maxPathSumUtil(root->left,maxi));
    int rightMaxPath=max(0,maxPathSumUtil(root->right,maxi));

    maxi=max(maxi,leftMaxPath+rightMaxPath+root->data);

    return max(leftMaxPath,rightMaxPath)+root->data;
}
int maxPathSum(Node*root){
   int maxi=-1e8;
   maxPathSumUtil(root,maxi);
   return maxi;
}

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
   int maxpathSum=maxPathSum(root);
   std::cout << "Maximum path sum is " << maxpathSum << std::endl;
}
                            