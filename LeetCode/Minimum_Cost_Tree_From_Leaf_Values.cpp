class Solution {
public: 
    int MaxNumber(vector<int>& arr,int start,int end){
        if(start>end)return 0;
        if(start==end)return arr[start];
        int ans=arr[start];
        for(int i=start;i<=end;i++){
            if(arr[i]>ans)ans=arr[i];
        }return ans;
    }
    int solve(int start,int end,vector<int>& arr, vector<vector<int>>&dp){
      if(start==end)return 0;
      if(dp[start][end]!=-1)return dp[start][end];
      int ans=INT_MAX;
      for(int i=start;i<end;i++){
           ans=min(ans,MaxNumber(arr,start,i)*MaxNumber(arr,i+1,end)+solve(start,i,arr,dp)+solve(i+1,end,arr,dp));
      }
      return dp[start][end]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
       return solve(0,arr.size()-1,arr,dp); 
    }
};