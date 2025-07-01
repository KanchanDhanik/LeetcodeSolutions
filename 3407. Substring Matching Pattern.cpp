/* 💡 Problem Statement:
In this problem, we are given two strings:

s (the main string)

p (the pattern string)

We need to check whether the pattern p occurs in s, with one twist: the pattern string p can contain a special character '*', which can match any number of characters (including zero) in the string s.

🧠 Approach:
To solve this, I divide the pattern string p into two parts:
 
The substring before the '*'

The substring after the '*'

I then:

Search for the occurrence of the "before" substring in s and store its index.

Search for the "after" substring in s, but only after the index where the "before" substring was found.

If either the "before" or the "after" substring is not found in the correct position in s, I return false.
If both are found in the correct order, I return true.
*/

class Solution {
public:
    bool hasMatch(string s, string p) {
        int pos=p.find('*');
        string before=p.substr(0,pos);
        string after=p.substr(pos+1);
        
        int beforepos=s.find(before);
        if(beforepos==-1)return false;
        int afterpos=s.find(after,before.size()+beforepos);
        if(afterpos==-1)return false;
        return true;
        
    }
};