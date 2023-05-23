class Solution{
	public:
	int solve(int n,vector<int>&dp)
	{
	   if(n==0)return 0;
	   else if(n==1)return 1;
	   if(dp[n]!=-1)return dp[n];
	   dp[n]=n;
	   for(int i=1;i*i<=n;i++){
	       dp[n]=min(dp[n],1+solve(n-i*i,dp));
	   }
	   return dp[n];
	}
	int MinSquares(int n)
	{
	    // Code here
	    vector<int>dp(n+1,-1);
	   return solve(n,dp);
	}
};