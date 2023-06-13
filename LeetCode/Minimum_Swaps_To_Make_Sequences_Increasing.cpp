class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int prev1,int prev2,int index,bool prevSwapped,vector<vector<int>>&dp){
        if(index>=nums1.size())return 0;
        int ans=INT_MAX;
        if(dp[index][prevSwapped]!=-1)return dp[index][prevSwapped];
        if(nums1[index]>prev1 && nums2[index]>prev2)
        {
           ans= min(ans,solve(nums1,nums2,nums1[index],nums2[index],index+1,false,dp));
        }
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solve(nums1,nums2,nums2[index],nums1[index],index+1,true,dp));
        }
        return dp[index][prevSwapped]= ans;

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(3,-1));
        return solve(nums1,nums2,-1,-1,0,false,dp);
    }
};