class Solution
{
public:
    map<string,int>dp;
    int solve(string arr,vector<string>brr){
        int n=arr.length();
        if(n==0)return 1;
        if(dp[arr]!=0)return dp[arr];
        
        for(int i=1;i<=n;i++){
            int f=0;
            string temp=arr.substr(0,i);
            for(int j=0;j<brr.size();j++){
                if(brr[j]==temp){
                if(solve(arr.substr(i),brr)==1)return dp[arr]=1;
                }
            }
        }
        return dp[arr]=0;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        int ans=solve(A,B);
        return ans;
    }
};