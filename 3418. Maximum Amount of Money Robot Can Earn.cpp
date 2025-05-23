/*Problem Context (Assumed)
You have a 2D grid coins with some positive and some negative values. You want to move from the top-left corner (0,0) to the bottom-right corner (n-1, m-1) by only moving right or down.

You want to maximize the sum of collected values along the path.

You are allowed to neutralize up to 2 negative coins (i.e., treat their negative value as zero, effectively skipping their loss).

Explanation of Code:
Variables:
n, m: Dimensions of the grid.

k: Number of negative coins neutralized so far (max 2 allowed).

dp[i][j][k]: Memoization table to store the best possible sum from cell (i, j) having neutralized k negative coins already.

coins[i][j]: Value at cell (i,j) (can be positive or negative).

The recursion explores the two possible moves from (i, j): down (i+1, j) or right (i, j+1).

Logic Breakdown:
Base cases:

If (i,j) goes out of bounds (beyond grid), return INT_MIN (invalid path).

If (i, j) is the bottom-right cell (n-1, m-1):

If the coin value is non-negative, return it.

If negative, check if you can neutralize it (k < 2):

If yes, return 0 (neutralized).

Otherwise, must accept the negative value.

Memoization check:

If dp[i][j][k] is already computed (not INT_MIN), return the cached value.

Current cell processing:

Let val = coins[i][j].

If val is non-negative:

Move down or right (recursive calls), keep k unchanged.

Take the best of those two paths.

Add current cell's value to best path sum.

If val is negative:

Option 1: Take the loss (add negative value), move down/right with k unchanged.

Option 2: If you still can neutralize (k < 2), neutralize this cell and move down/right, increasing k by 1.

Take the max of these two options.

Store and return the result in dp[i][j][k].
*/

class Solution {
public:
    int n,m;
    int helper(int i,int j,int k,vector<vector<int>>& coins,vector<vector<vector<int>>>&dp){
        if(i>=n ||j>=m)return INT_MIN;
        if(i==n-1 && j==m-1){
            int val=coins[i][j];
            if(val>=0)return val;
            else{
                if(k<2)return 0;
                else return val;
            }
        }
        if(dp[i][j][k]!=INT_MIN)return dp[i][j][k];
        int val=coins[i][j];
        int ans=INT_MIN;
        if(val>=0){
            int down=helper(i+1,j,k,coins,dp);
            int right=helper(i,j+1,k,coins,dp);
            int best=max(down,right);
            if(best!=INT_MIN)ans=best+val;
        }else{
            //we are left with two option take loss or nuetralise if k<2
            //option 1 take loss
            int down=helper(i+1,j,k,coins,dp);
            int right=helper(i,j+1,k,coins,dp);
            int best=max(down,right);
            if(best!=INT_MIN)ans=best+val;
            //option 2 if k<2 neutralise
            if(k<2){
                int d=helper(i+1,j,k+1,coins,dp);
                int r=helper(i,j+1,k+1,coins,dp);
                int best2=max(d,r);
                if(best2!=INT_MIN)ans=max(ans,best2);
            }
        }
        return dp[i][j][k]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return helper(0,0,0,coins,dp);
    }
};