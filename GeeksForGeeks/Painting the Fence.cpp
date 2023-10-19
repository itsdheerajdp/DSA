class Solution{
    public:
    int mod=1e9+7;
    long long solve(int n,int k,vector<int>&dp){
        if(n==0)return 0;
        else if(n==1)return k;
        else if(n==2)return k*k;
        if(dp[n]!=-1)return dp[n];
        long long a=solve(n-2,k,dp)*(k-1); // when in nth post we are painting same color as n-1 th post
        a=a%mod;
        long long b=solve(n-1,k,dp)*(k-1);// when in nth post we are not painting same color as n-1 th post
        b=b%mod;
        return dp[n]= (a+b)%mod ;
    }
    long long countWays(int n, int k) {
        vector<int>dp(n+1,-1);
    return solve(n,k,dp);
}
};