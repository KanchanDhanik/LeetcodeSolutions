/*✅ Explanation of zigzagTraversal Function
This function traverses a 2D grid in a zigzag pattern, but only includes elements at even column indices for each row. The direction alternates between left-to-right and right-to-left for consecutive rows.

🧠 Step-by-Step Logic
Initialization:

n: number of rows.

m: number of columns.

ans: to store the final zigzag traversal.

Corner Case:

If the grid is empty (n == 0 || m == 0), return an empty vector.

Offset Calculation:

offset = m % 2 ensures correct starting point when reversing the order from the last valid even index (e.g., if m = 5, last even index = 4; if m = 4, last even index = 2).

Row Traversal (Zigzag Pattern):

For each row i:

If flag == true: move left to right, pick grid[i][j] for even j (i.e., j += 2).

If flag == false: move right to left, pick from the last even index backward (i.e., j -= 2).

Flip the flag after each row to alternate direction.

Return Result:

The result is a zigzag traversal, considering only even-indexed columns per row.

*/


class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans;
        if(n==0|| m==0)return ans;
        int offset=m%2;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(flag){
                for(int j=0;j<m;j+=2){
                    ans.push_back(grid[i][j]);
                }
            }else{
                for(int j=m-1-offset;j>=0;j-=2){
                    ans.push_back(grid[i][j]);
                }
            }
            flag=!flag;
        }
        return ans;
        
    }
};