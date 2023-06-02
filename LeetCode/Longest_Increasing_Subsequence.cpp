class Solution {
public:
   int solve(int n,vector<int>&a,int index,int prevIndex,vector<vector<int>>&dp){
        if(index==n)return 0;
        if(dp[index][prevIndex+1]!=-1)return dp[index][prevIndex+1]; // as -1 is not valid index so we are just incrementing it to 0
        int include=0;
        //include
        if(prevIndex==-1 || a[index]>a[prevIndex]){
            include=1+solve(n,a,index+1,index,dp);
        }
        //exclude
        int exclude=solve(n,a,index+1,prevIndex,dp);
        dp[index][prevIndex+1]= max(include,exclude);// as -1 is not valid index so we are just incrementing it to 0
        return dp[index][prevIndex+1];
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums.size(),nums,0,-1,dp);
    }
};