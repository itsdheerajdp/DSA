#include <bits/stdc++.h> 
int solve(vector<int>num,int target,vector<int>&dp){
if(target==0){
    return 1;
}
else if(target<0)return 0;
int ans=0;
if(dp[target]!=-1)return dp[target];
for(int i=0;i<num.size();i++)
{   if(target-num[i]<0)continue;
    ans+=solve(num,target-num[i],dp);
}dp[target]=ans;
return dp[target];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    if(tar==0)return 1;
    vector<int>dp(tar+1,-1);
    return solve(num,tar,dp);
}
