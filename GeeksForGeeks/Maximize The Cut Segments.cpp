class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n,int x,int y,int z,vector<int>&dp){
        if(n==0)return 0;
        else if(n<x && n<y && n<z)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        int cutx=INT_MIN,cuty=INT_MIN,cutz=INT_MIN;
        cutx=1+solve(n-x,x,y,z,dp);
        cuty=1+solve(n-y,x,y,z,dp);
        cutz=1+solve(n-z,x,y,z,dp);
        if(cutx<0)cutx=INT_MIN; if(cuty<0)cuty=INT_MIN; if(cutz<0)cutz=INT_MIN;
        return dp[n]=max(cutx,max(cuty,cutz));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        int ans=solve(n,x,y,z,dp);
        if(ans==INT_MIN)return 0;else return ans;
    }
};