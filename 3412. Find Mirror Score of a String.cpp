/*🔍 Problem Understanding:
You are given a string s consisting of lowercase English letters. Each letter has a mirror based on its position in the alphabet (e.g., 'a' is mirror of 'z', 'b' is mirror of 'y', etc.). The goal is to pair each character with its mirror and calculate a score based on the distance between their positions.
The score is defined as the sum of the absolute differences between the indices of each matched pair.

✅ Approach:
Mapping Characters by Index:

We use an unordered_map<int, vector<int>> to keep track of the indices where each character occurs.

Instead of storing characters directly, we convert them to a number between 0 and 25 ('a' = 0, 'z' = 25).

Finding Mirror Characters:

For each character at index i, compute its mirror using:
mirror = 25 - ch
where ch = s[i] - 'a'.

Pairing Strategy:

If the mirror character has occurred before (i.e., mpp[mirror] is not empty), we:

Calculate the score as abs(i - mpp[mirror].back())

Add this score to ans

Remove the last index of the mirror character from the map (as it's now used)

If the mirror character hasn't occurred before, store the index of this character in mpp[ch].

Return the Final Score:

After traversing the whole string, return the accumulated score ans.
*/
class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<int,vector<int>>mpp;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'a';
            int mirror=25-ch;
            if(!mpp[mirror].empty()){
                ans+=abs(i-mpp[mirror].back());
                mpp[mirror].pop_back();
            }else{
                mpp[ch].push_back(i);
            }
        }
        return ans;
    }
};