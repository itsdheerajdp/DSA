class Solution {
public:
    bool solve(vector<int>&nums,int sum,int currSum,int index,vector<vector<int>>&dp){
        if(index>=nums.size())return false;
        if(currSum==sum)return true;
        if(currSum>sum)return false;
        if(dp[index][currSum]!=-1)return dp[index][currSum];
        //include
        bool include=solve(nums,sum,currSum+nums[index],index+1,dp);
        //exclude
         bool exclude=solve(nums,sum,currSum,index+1,dp);
         return dp[index][currSum]= include or exclude;
       
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%2!=0)return false;
        else{
            vector<vector<int>>dp(nums.size()+1,vector<int>(sum/2+1,-1));
            return solve(nums,sum/2,0,0,dp);
        }
    }
};