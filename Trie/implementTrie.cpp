/*Trie is a data structure in which one node can contains many children 
A trie (pronounced as "try") or prefix tree is a tree data structure used
 to efficiently store and retrieve keys in a dataset of strings. There are various applications
 of this data structure, such as autocomplete and spellchecker.*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*children[26];
    bool flag=false;

    bool containskey(char ch){
        return (children[ch-'a']!=NULL);
    }

    void putChar(char ch,struct Node*node){
        children[ch-'a']=node;
    }

    struct Node*getChar(char ch){
        return children[ch-'a'];
    }

    bool isEnd(){
        return flag;
    }
};
class Trie{
    struct Node*root;
    public:
    Trie(){
       root=new struct Node(); 
    }

    void insert(string word){
        struct Node*node=root;
        for(char &ch:word){
            if(!node->containskey(ch)){
                node->putChar(ch,new struct Node());
            }
            node=node->getChar(ch);
        }
        node->flag=true;
    }

    bool search(string word){
        struct Node*node=root;
        for(char &ch:word){
            if(!node->containskey(ch)){
                return false;
            }
            node=node->getChar(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix){
        struct Node*node=root;
        for(char &ch:prefix){
            if(!node->containskey(ch)){
                return false;
                }
            node=node->getChar(ch);
        }
        return true;
    }
};

int main(){
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    cout<<boolalpha<<trie.search("apple")<<endl;  // true
    cout<<boolalpha<<trie.search("app")<<endl;    // true
    cout<<boolalpha<<trie.search("banana")<<endl;// true
    cout<<boolalpha<<trie.search("ban")<<endl;   // false
    cout<<boolalpha<<trie.startsWith("app")<<endl;// true
    cout<<boolalpha<<trie.startsWith("ban")<<endl;// true
    return 0;
    }