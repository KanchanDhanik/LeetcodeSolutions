/*Problem Statement: Implement a program that takes a string 'S' as input and returns the number of
 distinct substrings of the given string, including the empty substring. Use a trie data structure to accomplish this.

Note:

A string ‘B’ is considered a substring of a string ‘A’ if ‘B’ can be obtained by deleting zero or 
more characters from the start and end of ‘A’.
Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’ such that the 
character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’ (i.e., X[i] != Y[i]).*/



#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node*links[26];
    bool flag=false;

    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }

    void putChar(char ch,struct Node*node){
        links[ch-'a']=node;
    }

    struct Node*getChar(char ch){
        return links[ch-'a'];
    }

};


int main(){
    string s;
    cin>>s;
    int n=s.size();
    int cnt=0;
    struct Node*root=new struct Node();
    for(int i=0;i<n;i++){
         struct Node*node=root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[i])){
                node->putChar(s[i],new struct Node());
                cnt++;
            }
            node=node->getChar(s[i]);
        }
    }
    cout<<cnt+1;
}