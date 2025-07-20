/*Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127*/
#include<bits/stdc++.h>
using namespace std;



struct Node{
    Node*children[2];

    bool containsbit(int bit){
        return (children[bit]!=NULL);
    }

    void put(int bit,struct Node*node){
        children[bit]=node;
    }

    struct Node*get(int bit){
        return children[bit];
    }
};


class Trie{
    private:
    struct Node*root;
    public:
    Trie(){
        root=new struct Node();
    }

    void insert(int num){
        struct Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsbit(bit)){
                node->put(bit,new struct Node());
            }
            node=node->get(bit);
        }
    }
    int getMaxXor(int num){
        struct Node*node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsbit(1-bit)){
                maxi=maxi|(1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxi;
    }
};


int findMaxXor(vector<int>&nums){
    Trie trie;

    for(auto &num:nums){
        trie.insert(num);
    }

    int maxxor=0;
    for(auto &num:nums){
        maxxor=max(maxxor,trie.getMaxXor(num));
    }
    return maxxor;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<endl<<endl;
    int maxxor=findMaxXor(nums);
    cout<<maxxor;
    return 0;
}