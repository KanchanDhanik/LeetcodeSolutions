class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int first=*max_element(nums.begin(),nums.end());
        int second=INT_MIN;
        int third=INT_MIN;
        int flag=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=first && second<nums[i]){
                flag++;
                second=nums[i];
            }
        }
        if(flag==0)return first;
        int flag2=0;
        for(int i=0;i<n;i++){
           if((third<nums[i] || nums[i]==INT_MIN ) && (nums[i]!=first && nums[i]!=second)){
            flag2++;
            third=nums[i];
           }
        }
        if(flag2>0){
            return third;
        }else{
            return first;
        }
    }
};