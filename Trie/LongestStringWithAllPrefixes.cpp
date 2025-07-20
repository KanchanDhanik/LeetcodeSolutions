/*Given a string array nums of length n. A string is called a complete string
 if every prefix of this string is also present in the array nums. Find the 
longest complete string in the array nums.

If there are multiple strings with the same length, return the lexicographically 
smallest one and if no string exists, return "None" (without quotes).


Examples:
Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]

Output : ninja

Explanation : The word "ninja" is the longest word which has all its prefixes 
present in the array.

Input : nums = [ "ninja" , "night" , "nil" ]

Output : None

Explanation : There is no string that has all its prefix present 
in array. So we return none*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*links[26];
    bool flag=false;

    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void putchar(char ch,struct Node*node){
        links[ch-'a']=node;
    }

    struct Node*getchar(char ch){
        return links[ch-'a'];
    }

};

class Trie{
    private:
    struct Node*root;
    public:
    Trie(){
        root=new struct Node();
    }

    void insert(string word){
        struct Node*node=root;
        for(auto&ch:word){
            if(!node->containskey(ch)){
                node->putchar(ch,new struct Node());
            }
            node=node->getchar(ch);
        }
        node->flag=true;
    }

    bool checkPrefix(string word){
        struct Node*node=root;
        for(auto&ch:word){
            if(node->containskey(ch)){
                node=node->getchar(ch);
                if(node->flag==false)return false;
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    Trie trie;
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(auto&word:arr){
        trie.insert(word);
    }

    string longest="";
    for(auto&it:arr){
        if(trie.checkPrefix(it)){
           if(it.length() > longest.length() || (it.length() == longest.length() && it < longest))
            longest=it;
        }
    }
    cout<<(longest==""?"none":longest);
}