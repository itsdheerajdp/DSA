int dp[21][21][21];
int solve(string a,int i,string b,int j,string c,int k,int n1,int n2,int n3){
    if(i>=n1 || j>=n2 || k>=n3)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int ans=0;
    if(a[i] == b[j] && a[i]==c[k]){
        ans=1+solve(a,i+1,b,j+1,c,k+1,n1,n2,n3);
    }
    else{
        ans=max(solve(a,i+1,b,j,c,k,n1,n2,n3),max(solve(a,i,b,j+1,c,k,n1,n2,n3),solve(a,i,b,j,c,k+1,n1,n2,n3)));
    }
    return dp[i][j][k]=ans;
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp,-1,sizeof(dp));
    return solve(A,0,B,0,C,0,n1,n2,n3);
}