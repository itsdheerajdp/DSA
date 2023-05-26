class Solution {
public:
    int solve(vector<int>&val,int i,int j,vector<vector<int>>&dp){
        if(j==i+1)return 0;
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        for(int k=i+1;k<j;k++){
        dp[i][j]=min(dp[i][j],val[i]*val[j]*val[k]+solve(val,i,k,dp)+solve(val,k,j,dp));
         
        }
    return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(values.size()+1,vector<int>(values.size()+1,INT_MAX));
       return solve(values,0,values.size()-1,dp);
  
    }
};