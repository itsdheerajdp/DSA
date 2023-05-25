class Solution{
public:
    int solve(vector<vector<int>>&mat,int i,int j,int &ans,vector<vector<int>>&dp){
        if(i>=mat.size() || j>=mat[0].size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int right_solution=solve(mat,i,j+1,ans,dp);
        int diagonal_solution=solve(mat,i+1,j+1,ans,dp);
        int down_solution=solve(mat,i+1,j,ans,dp);
        if(mat[i][j]==1){
            dp[i][j]=1+min(right_solution,min(diagonal_solution,down_solution));
            ans=max(ans,dp[i][j]);
        }
        else dp[i][j]=0;
        return dp[i][j];
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        solve(mat,0,0,ans,dp);
        return ans;
    }
};