3471. Find the Largest Almost Missing Integer
 
/*
You are given:

A vector nums

An integer k

You are supposed to:

Examine all subarrays of size k

For each subarray, collect distinct elements

Track how many different subarrays of size k each number appears in

Finally, return the largest number that appeared in exactly one subarray

🧠 Code Breakdown

unordered_map<int,int> mpp;
Keeps track of how many distinct subarrays of size k each number appears in.

🔁 Loop through all subarrays of size k:
for(int i=0; i+k <= n; i++) {
    unordered_set<int> st;
For each starting index i, you process a subarray of size k.

You use a set to ensure only unique elements from that subarray are considered.

💡 Count the frequency:
for(int j=i; j<i+k; j++) {
    if(st.find(nums[j])==st.end()) mpp[nums[j]]++;
    st.insert(nums[j]);
}
If nums[j] is not yet in the set for this subarray, increment its count in mpp.

Then insert it into the set.

This way, each number is counted once per subarray, not multiple times if repeated.

✅ Find the largest number that appeared in exactly one subarray:

for(auto it : mpp) {
    if(it.second == 1) {
        ans = max(ans, it.first);
    }
}
Iterate over your map to find all numbers that appeared in only one distinct subarray

Keep track of the maximum of these
*/
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int,int>mpp;
        for(int i=0;i+k<=n;i++){
            unordered_set<int>st;
            for(int j=i;j<i+k;j++){
                if(st.find(nums[j])==st.end())mpp[nums[j]]++;
                st.insert(nums[j]);
            }
        }
        for(auto it:mpp){
           if(it.second==1){
               ans=max(ans,it.first);
           }
        }
        return ans;
    }
};