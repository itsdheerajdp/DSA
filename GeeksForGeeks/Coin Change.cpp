class Solution {
  public:
    long long f(int i, int sum, int coins[],vector<vector<long long>> &dp) {
        if (i == 0) {
            if (sum % coins[i] == 0)
                return 1;
            else
                return 0;
        }

        if (sum == 0)
            return 1;
            
        if(dp[i][sum]!=-1)
        return dp[i][sum];

        long long notake = f(i - 1, sum, coins,dp);
        long long take = 0;  
        if (coins[i] <= sum)
            take = f(i, sum - coins[i], coins,dp);

        return dp[i][sum]=notake + take;
    }

    long long int count(int coins[], int N, int sum) {
        int i = N - 1;  
        vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
        return f(i, sum, coins,dp);
}
};