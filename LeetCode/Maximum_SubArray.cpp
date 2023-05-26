class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
       int largest_sum=nums[0];
       int temp_sum=0;
       for(int i=0;i<nums.size();i++){
           temp_sum+=nums[i];
           largest_sum=max(largest_sum,temp_sum);
           if(temp_sum<0)temp_sum=0;
       }
       return largest_sum;
    }
};