 PROBLEM STATEMENT:
 We are given a vector of 2-letter lowercase strings. Our task is to construct the longest possible palindromic string by concatenating some of these strings in any order. We must return the length of this longest palindrome.

🔍 Key Observations:
Palindromes read the same forward and backward. To maintain this, if we use a string like "ab" on the left, we must pair it with "ba" on the right.

We can count how many times each string appears using a 2D array count[26][26] representing all combinations of lowercase letters.

For any string s = "ab", we store count['a'-'a']['b'-'a']++.

If its reverse "ba" exists (count['b'-'a']['a'-'a'] > 0), we can pair them to contribute 4 characters to the palindrome.

🧠 Special Case – Palindromic Strings:
If the string is already a palindrome like "aa", "bb", etc., then it can be placed in the center of the palindrome. However, only one such string can be in the middle (as placing two breaks symmetry). We track this and add only one such string to the final length (contributing +2).

✅ Final Approach:
Initialize a 26×26 count array to store frequencies of all 2-letter strings.

Traverse the list of strings and fill the count array.

For each pair (i, j) where i != j:

Match as many pairs of "ij" and "ji" as possible.

For each pair matched, add 4 to the total length.

For each i, check if count[i][i] > 0. If so, we can use one palindromic string in the middle, add 2 to the length, and break (only one allowed).

Return the total length.




class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26];
        int len=0;
        memset(count,0,sizeof(count));
        for(string &word:words){
            int a=word[0]-'a';
            int b=word[1]-'a';
            if(count[b][a]>0){
                len+=4;
                count[b][a]--;
            }else{
                count[a][b]++;
            }
        }
        for(int i=0;i<26;i++){
            if(count[i][i]>0){
                len+=2;
                break;
            }
        }
        return len;
    }
};