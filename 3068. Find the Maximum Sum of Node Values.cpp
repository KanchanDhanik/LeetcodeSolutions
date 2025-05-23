class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
     int n=nums.size();
     vector<long long>delta(n);
     long long sum=0;
     for(int i=0;i<n;i++){
        sum+=nums[i];
        delta[i]=(nums[i]^k)-nums[i];
     }   
     sort(delta.begin(),delta.end(),greater<long long>());
     for(int i=0;i+1<n;i+=2){
        long long poschange=delta[i]+delta[i+1];
        if(poschange>0){
            sum+=poschange;
        }else{
            break;
        }
     }
     return sum;
    }
};