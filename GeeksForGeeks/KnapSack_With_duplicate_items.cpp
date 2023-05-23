class Solution{
public:
    int solve(int n,int lim,int val[],int wt[],int index,vector<vector<int>>&dp){
        if(index==n-1){
            int a=lim/wt[index];
            return val[index]*a;
        }
        if(dp[index][lim]!=-1)return dp[index][lim];
        int include=0;
        if(wt[index]<=lim)
        include=val[index]+solve(n,lim-wt[index],val,wt,index,dp);
        int exclude=solve(n,lim,val,wt,index+1,dp);
        dp[index][lim]= max(include,exclude);
        return dp[index][lim]; 
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solve(N,W,val,wt,0,dp);
    }
};