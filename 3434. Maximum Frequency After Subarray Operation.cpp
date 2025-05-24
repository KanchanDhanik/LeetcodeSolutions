/*✅ Problem Understanding:
You're given an array and a target number k. You want to find the maximum number of times k can appear in a subarray after performing one allowed operation:
You can choose one number i (from 1 to 50, excluding k) and pretend to convert any occurrences of i to k in a subarray to increase the count of k.

You cannot actually subtract a number to turn any value into k, as that would be too complex. So instead, the solution takes a smarter route.

🧠 Key Idea:
Since k is fixed and we can only pretend to convert one other number i into k, we simulate what would happen if we could turn some i values into k — only within a subarray.

📌 Solution Strategy:
First, count how many times k already exists in the array. This is your starting point.

Then, for every number i from 1 to 50 (excluding k), simulate the process:

Imagine scanning through the array.

For each element:

If it's the number i you want to convert, it increases your potential k count in a subarray.

If it's already k, it "competes" with the conversion (since we’re trying to find a region where i replaces k), so it slightly lowers the gain.

Any other number is ignored.

Use a Kadane's algorithm-style approach:

Keep track of the net gain (extra ks you’d get by converting i).

Reset your running total if it drops below zero.

Keep track of the highest gain you find.

Finally, the best gain you find (i.e., converting some i into k in some subarray) is added to your original count of k. This gives the maximum possible frequency of k you can achieve.

🏁 Conclusion:
You're essentially checking:
“For each number i other than k, what is the best subarray where converting i to k gives me the most new ks?”
Then you add that to the number of existing ks to get the final answer.
*/
This approach is efficient, avoids complex operations, and smartly uses a variation of Kadane’s Algorithm to find the optimal result.
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int cnt=0;
        for(int num:nums){
            if(num==k){
                cnt++;
            }
        }
        int ans=cnt;
        for(int i=1;i<=50;i++){
            int s=0;
            int maxi=0;
            if(i==k)continue;
            for(int x:nums){
                if(x==i)s++;
                else if(x==k)s--;
                if(s<0)s=0;
                maxi=max(maxi,s);
            }
            ans=max(ans,cnt+maxi);
        }
        return ans;
    }
};