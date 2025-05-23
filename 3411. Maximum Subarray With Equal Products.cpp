/*🧠 Problem Statement:
You're given an array of length n, and the task is to find the longest subarray where the following condition holds:


LCM(subarray) × GCD(subarray) = Product of all elements in the subarray
✅ Key Mathematical Insight:
There's a well-known identity for any set of positive integers:

LCM(a, b) × GCD(a, b) = a × b
This identity can be extended to a subarray:

LCM(arr[i..j]) × GCD(arr[i..j]) = arr[i] × arr[i+1] × ... × arr[j]
So, for each subarray, we want to check if this condition is satisfied.

🐢 Brute-Force Approach:
You used a brute-force method with two nested loops to try all possible subarrays. For each subarray, you computed:

GCD of elements

LCM of elements

Product of all elements

Then, you checked whether:

LCM × GCD == Product
⚠️ Problem: Integer Overflow
Even with long long, the product of several elements can exceed the storage capacity (around 9e18), causing overflow and incorrect results.

💡 Your Workaround: Using Reciprocals
To avoid overflow, you used a mathematical trick:

LCM × GCD = Product

(LCM × GCD) / Product ≈ 1
Instead of directly computing the product, you used:

if ((LCM × GCD × reciprocal_of_product) > 0.99999999)
This avoids computing the full product, which helps prevent overflow.

🔍 Why > 0.99999999?
Because floating-point calculations can have small rounding errors, checking:

value == 1
might not work correctly.

So instead, you compare with a slightly smaller threshold like:


value > 0.99999999
to account for precision issues.

🏁 Goal:
Whenever the condition is satisfied, you store the length of the subarray and update the maximum length found so far.


*/


class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            int currGCD=nums[i];
            int currLCM=nums[i];
            double reciprocal=1.0/nums[i];
            
            for(int j=i+1;j<n;j++){
                reciprocal/=nums[j];
                currGCD=gcd(currGCD,nums[j]);
                currLCM=lcm(currLCM,nums[j]);
                if((currGCD*currLCM*reciprocal)>0.99999999){
                maxlen=max(maxlen,j-i+1);
            }
            }
        }
        return maxlen;
    }
};