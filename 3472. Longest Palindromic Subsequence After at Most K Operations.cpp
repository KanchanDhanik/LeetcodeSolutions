/*📝 Problem Statement:
In this question, we are given a string s, and we are required to find the length of the longest palindromic subsequence (LPS). Additionally, we are allowed to perform at most k operations where each operation can change a character in the string.

A character in the string can be changed to its previous or next character in the English alphabet, with wrapping allowed — that is, 'a' can be changed to 'z' and 'z' can be changed to 'a'.

💡 Approach:
We use recursion to calculate the length of the LPS with at most k modifications. The recursive function is called with the starting index i and the ending index j of the string. At each step, we adjust the window (i to j) based on the logic explained below:

Base Case:

If i > j, we have crossed over the valid bounds — this is an invalid case, so we return 0.

If i == j, it means there's only one character left. A single character is always a palindrome, so we return 1.

Recursive Transitions:

We can skip the character at index i (move i forward), or skip the character at index j (move j backward), since we are looking for a subsequence, not a subarray. So both characters are optional.

We store the maximum result from skipping either character.

Modification Case:

If we want to change the character at index i to match the character at index j (or vice versa), we calculate the cyclic cost of doing so:

pgsql
Copy
Edit
cost = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]))
This is because characters wrap around in the alphabet.

If cost <= k, then we can perform this modification. We include both s[i] and s[j] in the palindrome, reduce k by cost, and recursively check the result on the subproblem i+1 to j-1.

Final Step:

We return the maximum result (res) computed from all possible valid options.

*/

class Solution {
public:
    int helper(int i,int j,string &s,int k,vector<vector<vector<int>>>&dp){
        if(i>j)return 0;
        if(i==j)return 1;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int res=helper(i+1,j,s,k,dp);
        res=max(res,helper(i,j-1,s,k,dp));
        int cost=min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
        if(cost<=k){
            res=max(res,2+helper(i+1,j-1,s,k-cost,dp));
        }
        return dp[i][j][k]=res;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return helper(0,n-1,s,k,dp);
    }
};