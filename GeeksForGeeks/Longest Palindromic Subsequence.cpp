class Solution{
  public:
    int LongestCommonSubsequence(string real,string rev,int i,int j,int n,vector<vector<int>>&dp){
        if(i>= n || j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(real[i]==rev[j]) return dp[i][j]= 1+LongestCommonSubsequence(real,rev,i+1,j+1,n,dp);
        else return dp[i][j]=max(LongestCommonSubsequence(real,rev,i+1,j,n,dp),LongestCommonSubsequence(real,rev,i,j+1,n,dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        string realString=A;
        reverse(A.begin(),A.end());
        string revString=A;
        int n=A.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return LongestCommonSubsequence(realString,revString,0,0,n,dp);
    }
};`