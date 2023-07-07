class Solution {
public:
    int solve(vector<int>&prices,int index,int timetoBuy,vector<vector<int>>&dp){
        if(index==prices.size())return 0;
        if(dp[index][timetoBuy]!=-1)return dp[index][timetoBuy];
        int profit=0;
        if(timetoBuy ){
            //include
            int include=-prices[index]+solve(prices,index+1,0,dp);
            //exclude
            int exclude=solve(prices,index+1,1,dp);
            profit=max(include,exclude);
        }
        else {
            //include
            int include=prices[index]+solve(prices,index+1,1,dp);
            //exclude
            int exclude=solve(prices,index+1,0,dp);
            profit=max(include,exclude);
        }
        return dp[index][timetoBuy]= profit;
        // return profit;

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};