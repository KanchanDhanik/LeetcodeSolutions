/*🧩 Problem Understanding
You're given:

n = 4 houses

Each house can be painted in 3 colors: 0, 1, or 2

cost[i][j] = cost to paint house i with color j

Rules:

No two adjacent houses (i.e., i and i+1) can have the same color.

Also, each house is considered adjacent to its mirror house at index n - i - 1. So house 0 is adjacent to house 3, house 1 to house 2, and vice versa.

🧠 Approach
We must pick a color for each house such that:

Adjacent and mirror houses have different colors

The total painting cost is minimized

We use dynamic programming to try all combinations of valid colorings:

For each pair (i, n - i - 1), choose two different colors

For each such choice, recursively compute the cost for remaining houses

Track and return the minimum among all valid combinations
*/
class Solution {
public:
    long long helper(int i,int last,int next,vector<vector<int>>& cost,vector<vector<vector<long long>>>&dp,int n){
        if(i>=n/2)return 0;
        if(dp[i][last+1][next+1]!=-1)return dp[i][last+1][next+1];
        long long mini=LLONG_MAX;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j!=k && j!=last && k!=next){
                    mini=min(mini,cost[i][j]+cost[n-i-1][k]+helper(i+1,j,k,cost,dp,n));
                }
            }
        }
        return dp[i][last+1][next+1]=mini;
        
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(4,vector<long long>(4,-1)));
        return helper(0,-1,-1,cost,dp,n);
    }
};