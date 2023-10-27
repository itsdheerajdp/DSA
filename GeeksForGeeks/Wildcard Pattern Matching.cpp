class Solution{
  public:
/*You are required to complete this method*/
    int solve(string pattern,string str,int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i>=n && j>=m )return 1;
        if(i>=n && j<m)return 0;
        if(j>=m && i<n){
            while(i<n){
                if(pattern[i]!='*')return 0;
                i++;
            }
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans;
        if(pattern[i]==str[j] || pattern[i]=='?')ans=solve(pattern,str,i+1,j+1,n,m,dp);
        else if(pattern[i]=='*'){
            int case1 = solve(pattern,str,i+1,j,n,m,dp);// assuming * as empty string
            int case2 = solve(pattern,str,i,j+1,n,m,dp); // assuming * as "str[j]*"
            ans= case1 or case2;
        }
        else{
            ans= 0;
        }
        return dp[i][j]=ans;
        
    }
    int wildCard(string pattern,string str)
    {
        int n=pattern.size();
        int m=str.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(pattern,str,0,0,n,m,dp);
    }
};